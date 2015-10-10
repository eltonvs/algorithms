#!/usr/bin/env python
# -*- coding: UTF-8 -*-

def nth_fibonacci(n):
    return round((((1 + 5**(1/2))/2)**n - ((1 - 5**(1/2))/2)**n)/(5**(1/2)))

n = int(input("Enter the nth number of the fibonacci sequence you want: "))
print("The nth number of fibonacci sequence is:", nth_fibonacci(n))
