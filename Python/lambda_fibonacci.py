#!/usr/bin/env python
# -*- coding: UTF-8 -*-

fib = lambda x: 1 if x == 0 or x == 1 else fib(x - 1) + fib(x - 2)

#Example
for i in range (10):
    print("fib(%i) = %i" %(i, fib(i)))
