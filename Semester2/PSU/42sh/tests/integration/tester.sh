#!/bin/bash

MYSHELL="$PWD/../../42sh"
REFER="/bin/tcsh -f"

# Add the test suite files below one per line
SUITES=(
  'test_basic.toml'
  'test_builtins.toml'
  'test_errors.toml'
  'test_globbing.toml'
  'test_inhibitors.toml'
  'test_var_expansion.toml'
)

# Undefines any previously defined bash function
for i in `env | grep BASH_FUNC_ | cut -d= -f1`; do
  f=`echo $i | /usr/bin/sed s/BASH_FUNC_//g | /usr/bin/sed s/%%//g`
  unset -f $f
done

CAT=`which cat`
GREP=`which grep`
SED=`which sed`
RM=`which rm`
TR=`which tr`
CHMOD=`which chmod`
CP=`which cp`
DIFF=`which diff`
TEST=`which test`
TPUT=`which tput`
DATE=`which date`
PRINTF=`which printf`

# Gets the value of string properties with the first argument as names
function get_string_property {
  $SED -ne "s/^$1\s*=\s*\(.*\)\s*$/\1/p" | $SED -e "s/^\(\"\(.*\)\"\)\|\('\(.*\)'\)$/\2\4/"
}

function run_script {
  SC="$1"
  echo "$SC" > /tmp/.tmp.$$
  . /tmp/.tmp.$$
  $RM -f /tmp/.tmp.$$
}

function prepare_test {
  local testfn="/tmp/.tester.$$"
  local runnerfn="/tmp/.runner.$$"
  local refoutfn="/tmp/.refer.$$"
  local shoutfn="/tmp/.shell.$$"

  WRAPPER="$runnerfn"

  echo "#!/bin/bash" > $runnerfn
  echo "$SETUP" >> $runnerfn
  echo "/bin/bash -c '"$testfn" | "$MYSHELL" ; echo Shell exit with code \$?' > "$shoutfn" 2>&1" >> $runnerfn
  echo "$CLEAN" >> $runnerfn
  echo "$SETUP" >> $runnerfn
  echo "$TCSHUPDATE" >> $runnerfn
  echo "/bin/bash -c '"$testfn" | "$REFER" ; echo Shell exit with code \$?' > "$refoutfn" 2>&1" >> $runnerfn
  echo "$CLEAN" >> $runnerfn

  echo "#!/bin/bash" > $testfn
  echo "$TESTS" | $TR "²" "\n" >> $testfn

  $CHMOD 755 $testfn
  $CHMOD 755 $runnerfn
}

# Parameters:
# 1 - suite file contents
# 2 - suite name
# 3 - test id
# Returns 0 if test passed, 1 otherwise
function run_test {
  local suite_contents=$1
  local suite=$2
  local id=$3

  local properties=`echo "$suite_contents" | $SED -ne  "/^\[$id\]\$/,/^\[.*\]$/{/^\[.*\]$/d;p}"`

  # extract 'tests' multiline property first...
  TESTS=`echo "$properties" | $SED -ne '/^tests\s*=\s*"""$/,/^"""$/{/^tests\s*=\s*"""$/d;/^"""$/d;p}'`
  # then remove it from the property list
  properties=`echo "$properties" | $SED -ne '/^tests\s*=\s*"""$/,/^"""$/d;p'`

  SETUP=`echo "$properties" | get_string_property 'setup'`
  CLEAN=`echo "$properties" | get_string_property 'clean'`
  NAME=`echo "$id"`
  TCSHUPDATE=`echo "$properties" | get_string_property 'tcsh-update'`

  # generate run scripts...
  prepare_test
  local start=$($DATE +%s%2N)
  # then execute them
  $WRAPPER
  
  # measure time elapsed
  local end=$($DATE +%s%2N)
  local test_time=$($PRINTF %.2fs $(($end - $start))e-2)

  if $DIFF -U3 /tmp/.refer.$$ /tmp/.shell.$$ > /tmp/.diff.$$; then
    echo -e "[${GREEN}PASS${NC}] $suite::$id ($test_time)"
    return 0
  else
    local description=`echo "$properties" | get_string_property 'description'`

    echo -e "[${RED}FAIL${NC}] $suite::$id ($test_time)" 
    [ ! -z "$description" ] && echo -e "[${BLUE}----${NC}] Description: $description"
    echo -e "[${BLUE}----${NC}] Outputs differ:"
    $CP /tmp/.refer.$$ /tmp/.refer.$$.$id
    $CP /tmp/.shell.$$ /tmp/.shell.$$.$id
    $DIFF -U3 /tmp/.refer.$$.$id /tmp/.shell.$$.$id > /tmp/.diff.$$.$id
    while IFS= read -r line; do
      echo -e "[${BLUE}----${NC}] $line"
    done < /tmp/.diff.$$.$id
    return 1
  fi
}

# Parameters:
# 1 - suite file path
# Returns 0 if all tests passed, 1 otherwise
function run_test_suite {
  local test_file="$1"
  
  if [ ! -f "$test_file" ]; then
    echo "No such test suite at path $test_file" >&2
    return 1
  fi

  local suite_contents=`$CAT $test_file`
  local suite_properties=`echo "$suite_contents" | $SED -ne '1,/^\[.*\]$/{/^\[.*\]$/d;p}'`
  local suite=`echo "$suite_properties" | get_string_property 'suite'`
  local tested=0
  local passing=0
  local failing=0

  for id in `echo "$suite_contents" | $SED -ne '/\[.*\]/!d;s/\[\(.*\)\]/\1/p' "$1"`; do
    local path_backup=$PATH

    if run_test "$suite_contents" "$suite" "$id" 1; then
      passing=$(($passing + 1))
    else
      failing=$(($failing + 1))
    fi
    tested=$(($tested + 1))
    export PATH=$path_backup
  done
  echo -e "[${BLUE}====${NC}] ${BOLD}Synthesis: Tested:${NC} ${BLUE}${tested}${NC} | ${BOLD}Passing:${NC} ${GREEN}${passing}${NC} | ${BOLD}Failing:${NC} ${RED}${failing}${NC}"
  [ $failing -eq 0 ]
}

function print_usage {
  echo "Usage: $0 [--color=auto|always|never]" >&2
}

if [ ! -f $MYSHELL ]; then
  echo "$0: shell $MYSHELL not found" >&2
  exit 1
fi

COLOR=auto

# Argument parsing
for i in "$@"; do
  case $i in
    --color)
    echo "$0: color parameter requires a value" >&2
    exit 1
    ;;
    --color=*)
    COLOR="${i#*=}"
    if [[ "$COLOR" != 'auto' && "$COLOR" != 'always' && "$COLOR" != 'never' ]]; then
      echo "$0: invalid argument '$COLOR' for '--color', valid arguments are 'always', 'never', or 'auto'"
      exit 1
    fi
    shift
    ;;
    -h | --help)
    print_usage
    exit 0
    ;;
  esac
done

if [ $COLOR == 'auto' ]; then
  if test -t 1; then
    COLOR='always'
  else
    COLOR='never'
  fi
fi

if [[ $COLOR == 'always' && "$TERM" != 'dumb' ]]; then
  NC="\033[0m"
  BOLD="\033[0;1m"
  RED="\033[0;31m"
  GREEN="\033[0;32m"
  BLUE="\033[0;34m"
fi

code=0
for test_file in ${SUITES[@]}; do
  run_test_suite "$test_file"
  ret=$?
  [ ! $ret -eq 0 ] && code=$ret
done
exit $code
