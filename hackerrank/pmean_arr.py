#!/usr/bin/env python

if __name__ == '__main__':
    pmean = 0
    sum_of_elements = 0
    n = int(raw_input())
    arr = map(int, raw_input().split())
    for i in range(0, n):
        pmean = pmean + (arr[i] * (i+1))
        sum_of_elements = arr[i] + sum_of_elements

    result_pmean = pmean
    for i in range(0, n):
        pmean = pmean + sum_of_elements - arr[n-i-1] * n
        if (pmean > result_pmean):
            result_pmean = pmean

    print result_pmean




