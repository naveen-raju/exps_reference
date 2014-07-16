#!/usr/bin/env python

from sys import stdin
import pdb

tc = int (stdin.readline().rstrip().split()[0])
val = []

for i in range(0,tc):
    input = int (stdin.readline().rstrip().split()[0])
    if input%2 == 1:
        val.append((input/2)*(input/2 + 1))
    else: 
        val.append((input/2)*(input/2))

for item in val:
    print item

