#!/usr/bin/env python
from sys import stdin
import pdb

input = stdin.readline().split()
width = stdin.readline().split()

input = map(int, input)
width = map(int, width)

#pdb.set_trace()
for values in range(0,input[1]):
    tc = stdin.readline().split()
    tc = map(int, tc)
    sum_width_from_i_to_j = 0 
    count_3 = 0
    count_2 = 0
    count_1 = 0

    for i in range(tc[0], tc[1]+1):
        sum_width_from_i_to_j = sum_width_from_i_to_j + width[i]
        if width[i] == 3:
            count_3 = count_3 + 1
        elif width[i] == 2:
            count_2 = count_2 + 1
        else: 
            count_1 = count_1 + 1
    
        distance = tc[1] - tc[0] + 1
   
    if ((count_3 * 3) == sum_width_from_i_to_j):
        print 3
    elif (count_2 > 0 and count_1 == 0):
        print 2 
    else: 
        print 1 
