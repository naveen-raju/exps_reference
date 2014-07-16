#!/usr/bin/env python
# Enter your code here. Read input from STDIN. Print output to STDOUT

def max_toys(prices, rupees):#Compute and return final answer over here
    answer = 0
    toys = 0
    prices.sort()
    for i in prices:
        toys = toys + i
        if toys > rupees:
            break
        answer = answer + 1
    return answer

if __name__ == '__main__':
    n, k = map(int, raw_input().split())
    prices = map(int, raw_input().split())
    print max_toys(prices, k)

