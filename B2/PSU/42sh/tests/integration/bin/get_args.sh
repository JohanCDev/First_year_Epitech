#!/bin/bash

# Prints all the arguments of the script (including argv[0]), preceded by their index.

echo "[0]: '$0'"
i=1
for arg in $@; do
    echo "[$i]: '$arg'"
    i=$(($i + 1))
done
