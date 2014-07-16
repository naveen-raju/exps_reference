#!/usr/bin/env python

def possible(arr, n):
    total_sum = sum(arr)
    left_sum = total_sum
    right_sum = 0
    for i in range(0, n):
        left_sum = left_sum - arr[n-i-1]
        if left_sum == right_sum:
            return "YES"
        right_sum = right_sum + arr[n-i-1]
    return "NO"


if __name__ == '__main__':
    ntc = int(raw_input())
    x = []
    for i in range(0, ntc):
        n= int(raw_input())
        arr = map(int, raw_input().split())
        x.append(possible(arr, n))

    for each in x:
        print each



