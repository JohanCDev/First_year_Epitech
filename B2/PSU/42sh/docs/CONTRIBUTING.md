# How to contribute

#### Table Of Contents

[Coding Conventions](#coding-conventions)
  * [Naming](#naming)
  * [Line Continuations](#line-continuations)
  * [Functions](#functions-1)
  * [C Headers](#c-headers)
  * [Source Headers](#source-headers)
  * [Documentation](#documentation)
  * [Types](#types)
  * [Assertions](#assertions)

[Submitting Changes](#submitting-changes)

[Tips and Tricks](#tips-and-tricks)
  * [VSCode](#vscode)

## Coding Conventions

Follow [Epitech's Coding Style™](https://intra.epitech.eu/file/Public/technical-documentations/epitech_c_coding_style.pdf). However refrain from using tools like the `norminette` to check for errors because there is currently no tool good enough not to spew thousands of errors over totally compliant code.

The use of `clang-format` through your IDE is **strongly** encouraged, the project already contain the neccessary style config file.  For VSCode users: The C/C++ extension has support for clang-format, use the format document command or enable format on save (`editor.formatOnSave`)

### Naming

All names should be in english:
  * proper word ordering: ~~length_str~~ -> str_length
  * no french words: ~~mnemonique~~ -> mnemonic

Definition names (functions, types, constants, defines) should be prefixed by the program/library short name (`sh_`/`SH_` in this project).  

The use of the `my_` prefix **is reserved** by the LibMy library, **do not** use this in the project!

Example:
```c
int get_lenght_str(char const *str); // NOT OK!
int sh_get_str_length(char const *str); // OK

#define MAGIC_MACRO (0xcafebabe) // NOT OK!
#define SH_MAGIC_MACRO (0xcafebabe) // OK
```

#### Functions

Functions that manipulate a type (for therein called *methods*) should always have the type's name as a prefix:
```c
int sh_execute_bytecode(sh_vm_t *vm, char const *bytes); // NOT OK!
int sh_vm_execute_bytecode(sh_vm_t *vm, char const *bytes); // OK
```

#### Structures and Unions

Follow general naming conventions, but do not add a `_s`/`_u` suffix.
```c
// DON'T DO THAT
struct sh_parser_s {
    /*...*/
};

// OK
struct sh_parser {
    /*...*/
};
```

Member names should never contain the name of their owner (avoids redundancy).
```c
struct sh_token_s {
    int token_value; // NOT OK!
    int value; // OK
    sh_token_type_t type // OK!
};
```

#### Enums

Follow general naming conventions, but do not add a `_e` suffix.
The constants' names should have the program/library's short name and the name (or part) of the name of the surrounding `enum` as a prefix.

All constants should be terminated by a comma (`,`).

```c
// DON'T DO THAT
enum sh_token_type_e {
    STRING,
    Number
};

// OK
enum sh_token_type {
    SW_TOKEN_STRING,
    SW_TOKEN_NUMBER,
};
```

### Line Continuations

Do not use backslashes (`\`) for marking a line split.
The lines following the split must be indented.

```c
// Nope!
fight_t *fight_create(battle_t *battle, int nb_ennemies, \
struct player_t *player);

// Better!
fight_t *fight_create(battle_t *battle, unsigned ennemy_count,
    player_t *player);
```

### Functions

Functions that manipulate a type (for therein called *methods*) should always take that type as their **first parameter**.
```c
int sh_vm_execute_bytecode(char const *bytes, sh_vm_t *vm); // NOT OK!
int sh_vm_execute_bytecode(sh_vm_t *vm, char const *bytes); // OK
```

For the most part, source files should be named after the main function in it, minus the program/library prefix:
`sh_vm_execute_bytecode()` may be stored in `vm_execute_bytecode.c`

#### Common Function definitions
  * `<type name>_init(<type name> *mystruct, params...)`:  
  Intializes the structure at `mystruct` with the given parameters, `dst` must be a valid location.

  * `<type name> *<type name>_create(params...)`:  
  Allocates `sizeof(<type name>) bytes`,initializes them using `<type_name>_init(bytes, params)`, then returns the allocated pointer, or `NULL` if an error occured.

  * `void <type name>_drop(<type name> *mystruct) *mystruct)`:
    Unitializes the *internal* memory of mystruct, without `free`'ing the pointer.

  * `void <type name>_destroy(<type name>) *mystruct)`:
    Unitializes the *internal* memory of mystruct, then `free`s the pointer.

  * `<prop type> <type_name>_get_<prop name>(<type name> const *mystruct)`:  
    Retrieves the property `<prop_name>` of type `<prop type>` from `mystruct`.

  * `void <type_name>_set_<prop name>(<type name> const *mystruct, <prop type> value)`:  
    Updates the property `<prop_name>` of type `<prop type>` in `mystruct` to `value`.

### C Headers

C headers (`.h` files) should not `#include` other headers ***unless absolutely neccessary***

Includes of this type should be located in `.c` instead.
```c
#include <sys/types.h>

#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <uinstd.h>
#include <stdio.h>
#include <sys/stat.h>

// ...
```

Split your headers into multiple files when they contains parts that are unrelated to each other.

Use `#include` with moderation, you do not need to include an entire library's includes if you only need one definition from a specific header. 

The header guard should follow this format:  
`__<PROJECT NAME>_<SUBDIR 1>_...<SUBDIR X>_<HEADER NAME>_H__`

Where:
  * `<PROJECT NAME>` is the name of the project.
  * `<SUBDIR 1> <SUBDIR X>` are the names of the parent directories?
  * `<HEADER_NAME>` is the name of the file, minus the `.h`

Example:
```c
#ifndef __SH_ASM_PARSER_H__
#define __SH_ASM_PARSER_H__

/* definitions goes here */

#endif // !defined(__SH_ASM_PARSER_H__)
```

### Source Headers

Source headers should be of the format:
```c
/*
** EPITECH PROJECT, 2021
** PROJECT_NAME
** File description:
** FILE_DESCRIPTION
*/
```

Where `PROJECT_NAME` is 42sh and `FILE_DESCRIPTION` is a **sentence** description what the file does (one or two words **are not OK**)

### Documentation

All (non-internal) defintions should be documented in their include file, to decribe their purpose, usage, (in)valid values, ...

Documents can follow either format:

* Simple sentence:
  ```c
  /// Stores the info as pos (x, y) to dst (cannot be null) and returns some constant.
  some_result_t function_to_document(my_struct_t *dst, int x, int y);
  ```

* A Javadoc-style [Doxygen](https://www.doxygen.org) comment:
  ```c
  /// Stores the info as pos (x, y) to dst.
  ///
  /// @param[out] dst Where the ??? info will be stored, cannot be @c NULL.
  /// @param x The horizontal position, must be lower than 4242.
  /// @param y The vertical position.
  ///
  /// @returns @c SOME_CONSTANT_1 if succeded, or @c SOME_CONSTANT_X on error 35.
  some_result_t function_to_document(my_struct_t *dst, int x, int y);
  ```

Note that the latter format is preffered but the former style is still good enough.

### Types

Always prefer using the type most adapter to the situation (`int` is not always the answer):
  * Use `unsigned` variants when the variable cannot be negative. (pro tip: `unsigned` is the same as `unsigned int`!)
  * Use `size_t` for indexing memory.
  * Do not use non-standard types like `uint` (looking at you CrossbowBoy!)

### Assertions

The use of `assert()` is encouraged the check invariants in debug mode (such as `NULL` parameters)

```c
#include <assert.h>

short my_func(char *buf, size_t *pos, size_t buf_len)
{
    // check parameters using assert()
    assert(buf != NULL);
    assert(pos != NULL && *pos < buf_len);
    /* ... */
}
```

## Submitting Changes

To alter the master branch, please send a [GitHub Pull Request](https://github.com/EpitechIT2020/B-PSU-210-NAN-2-1-42sh-yanis.guaye/pull/new/master) with a clear list of what you've done (read more about [pull requests](http://help.github.com/pull-requests/)).
Please follow our coding conventions (below) and make sure all of your commits are atomic (one feature per commit).

Always write a clear log message for your commits. One-line messages are fine for small changes, but bigger changes should look like this:
```sh
    $ git commit -m "A brief summary of the commit
    > 
    > A paragraph describing what changed and its impact."
```

## Tips and Tricks

### VSCode
  * The [CMake Tools extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) allows the editor to know the structure of CMake projects, enabling features like builting, debugging, testing, jumping to definition and more!
