#! /usr/bin/env python
from sys import stdin
import pdb

average = 0
val = 0
tc_val = stdin.readline().rstrip().split()
tc_val = map(int, tc_val)

for i in range(0,tc_val[1]):
    #pdb.set_trace()
    input = stdin.readline().rstrip().split()
    input = map(int, input)
    val = val + (input[1] - input[0] + 1) * input[2]
average = val/tc_val[0]
print average




