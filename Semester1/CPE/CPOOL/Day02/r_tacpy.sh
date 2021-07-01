#!/bin/bash

cut -d: -f 1 | rev | sed -n '0~2p' | sort -r | sed -ne "${MY_LINE1} , ${MY_LINE2} p" |  tr "\n" "," | sed -re 's/,$/./g'  | awk -F ',' -v OFS=", " '$1=$1'
