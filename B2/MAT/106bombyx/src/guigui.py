#! /usr/bin/python3

import sys
import math
import os
import random

def usage_help():
    print("USAGE\n\t./106bombyx n [k | i0 i1]")
    print("DESCRIPTION\n\tn\tnumber of first generation individuals\t")
    print("\tk\tgrowth rate from 1 to 4\t")
    print("\ti0\tinitial generation (included)\t")
    print("\ti1\tfinal generation (included)")
    sys.exit()

def check_valid_string(str):
    
    i = 0
    
    while (i < len(str)):
        if (str[i] < '.' and str[i] < '0' or str[i] > '9'):
            sys.exit(84)
        i = i + 1

def growth_rate(n, k):
    
    i = 1
    
    print ("%i "%i, "%.2f"%n, sep = "")
    while (i < 100):
        n = k * n * ((1000 - n) / 1000)
        if (n < 0):
            n = 0
        i = i + 1
        print("%d "%i, "%.2f"%n, sep = "")

def growth_rate2(n, i0, i1):
    
    k = 1
    x = n
    
    while (k < 4):
        i = 1
        n = float(x)
        while (i < i0):
            n = k * n * ((1000 - n) / 1000)
            if (n < 0):
                n = 0
            i = i + 1
        while (i <= i1):
            print("%.2f "%k, "%.2f"%n, sep = "")
            n = k * n * ((1000 - n) / 1000)
            if (n < 0):
                n = 0
            i = i + 1

        k = k + 0.01

def main():
    if (len(sys.argv) == 2 or len(sys.argv) == 3 or len(sys.argv) == 4):

        i = 0
        nb_arg = len(sys.argv)
        k = 1

        if (sys.argv[1] == "-h"):
            usage_help()
        elif (nb_arg == 2):
                sys.exit(84)
        while (k < nb_arg):
            check_valid_string(sys.argv[k])
            k = k + 1

        if (float(sys.argv[1]) < 0):
            sys.exit(84)

        if (nb_arg == 3):
            n = float(sys.argv[1])
            if (float(sys.argv[2]) < 1 or float(sys.argv[2]) > 4):
                sys.exit(84)
            k = float(sys.argv[2])
            growth_rate(n, k)

        elif (nb_arg == 4):
            n = float(sys.argv[1])
            try:
                i0 = int(sys.argv[2])
                i1 = int(sys.argv[3])
            except ValueError:
                sys.exit(84)
            if (i0 >= i1):
                sys.exit(84)
            growth_rate2(n, i0, i1)

    else:
        sys.exit(84)
main()