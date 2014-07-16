#!/usr/bin/env python

from sys import stdin
import pdb

tc = int (stdin.readline().rstrip().split()[0])
output = []

#pdb.set_trace()
for i in range(0,tc):
    input = stdin.readline().rstrip().split()
    input = map(int, input)

    num_chocs = input[0]/input[1]  # bought from $

    num_wrappers_refundable = num_chocs/input[2]
   
    remaining_wrappers = num_chocs%input[2]
    
    num_chocs = num_chocs + num_wrappers_refundable
   
    if (remaining_wrappers + num_wrappers_refundable >= input[2]):
         num_chocs = num_chocs + ((remaining_wrappers + num_wrappers_refundable)/input[2])

    output.append(num_chocs)

for item in output:
    print item

