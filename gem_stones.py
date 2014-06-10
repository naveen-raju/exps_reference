#! /usr/bin/env python
from sys import stdin
import pdb

gem_stones = 0
n_rocks= int (stdin.readline().rstrip().split()[0])

master_dict = {}
dict_array = [] 

#pdb.set_trace()
for i in range(0,n_rocks):
    strread = stdin.readline().rstrip()
    # build a temp dictionary 
    local_dict = {}
    for j in range(0, len(strread)):
        local_dict.update({strread[j]:1})
    # update master dictionary
    if len(master_dict) == 0:
        master_dict = local_dict
    else: 
        for key in local_dict.keys():
            x =  master_dict.get(key)
            if x != None:
                master_dict.update({key:x+1})

for key in master_dict.keys():
    if master_dict.get(key) == n_rocks:
        gem_stones = gem_stones + 1

#print gem_stones
print gem_stones
