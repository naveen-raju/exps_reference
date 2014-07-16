#!/usr/bin/env python

def possible(arr_a, arr_b, n , k):
    arr_a.sort()
    arr_b.sort()
    arr_b.reverse()
    for i in range(0, n):
        if arr_a[i] + arr_b[i] < k:
            return "NO"
    return "YES"

if __name__ == '__main__':
    ntc = int(raw_input())
    x = []
    for i in range(0, ntc):
        n, k = map(int, raw_input().split())
        arr_a = map(int, raw_input().split()) 
        arr_b = map(int, raw_input().split()) 
        x.append(possible(arr_a, arr_b, n, k)) 
    for each in x:
        print each
        

