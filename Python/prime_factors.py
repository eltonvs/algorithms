#!/usr/bin/env python
# -*- coding: UTF-8 -*-

def prime_factors(n, f = 2):
    return [] if n < f else [f] + prime_factors(n/f) if n%f == 0 else prime_factors(n, f+1)

n = int(input("Enter a number to be factorized: "))
print("The prime factors are:", prime_factors(n))
