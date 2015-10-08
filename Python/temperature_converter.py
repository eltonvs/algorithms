#!/usr/bin/env python
# -*- coding: UTF-8 -*-

def get_fahrenheit(t, e):
    if e.upper() == 'K': return 9*get_celsius(t, 'K')/5 + 32
    elif e.upper() == 'C': return 9*t/5 + 32
    elif e.upper() == 'RE': return t*9/4 + 32
    elif e.upper() == 'RA': return t - 459.67
    elif e.upper() == 'N': return t*60/11 + 32
    elif e.upper() == 'D': return 212 - t*6/5
    elif e.upper() == 'RO': return (t - 7.5)*24/7 + 32
    else: return t

def get_kelvin(t, e):
    if e.upper() == 'F': return get_celsius(t, 'F') + 273.15
    elif e.upper() == 'C': return t + 273.15
    elif e.upper() == 'RE': return t*5/4 + 273.15
    elif e.upper() == 'RA': return t*5/9
    elif e.upper() == 'N': return t*100/33 + 273.15
    elif e.upper() == 'D': return 373.15 - t*2/3
    elif e.upper() == 'RO': return (t - 7.5)*40/21 + 273.15
    else: return t

def get_celsius(t, e):
    if e.upper() == 'F': return (t-32)*5/9
    elif e.upper() == 'K': return t - 273.15
    elif e.upper() == 'RE': return t*5/4
    elif e.upper() == 'RA': return t*5/9 - 273.15
    elif e.upper() == 'N': return t*100/33
    elif e.upper() == 'D': return 100 - t*2/3
    elif e.upper() == 'RO': return (t - 7.5)*40/21
    else: return t

def get_reamour(t, e):
    if e.upper() == 'F': return (t - 32)*4/9
    elif e.upper() == 'K': return get_celsius(t, 'K')*4/5
    elif e.upper() == 'C': return t*4/5
    elif e.upper() == 'RA': return (t - 491.67)*4/9
    elif e.upper() == 'N': return t*80/33
    elif e.upper() == 'D': return 80 - t*8/15
    elif e.upper() == 'RO': return (t - 7.5)*32/21
    else: return t

def get_rankine(t, e):
    if e.upper() == 'F': return t + 459.67
    elif e.upper() == 'K': return t*9/5
    elif e.upper() == 'C': return get_kelvin(t, 'C')*9/5
    elif e.upper() == 'RE': return t*9/4 + 491.67
    elif e.upper() == 'N': return t*60/11 + 491.67
    elif e.upper() == 'D': return 671.67 - t*6/5
    elif e.upper() == 'RO': return (t - 7.5)*24/7 + 491.67
    else: return t

def get_newton(t, e):
    if e.upper() == 'F': return (t - 32)*11/60
    elif e.upper() == 'K': return get_celsius(t, 'K')*33/100
    elif e.upper() == 'C': return t*33/100
    elif e.upper() == 'RA': return (t - 491.67)*11/60
    elif e.upper() == 'RE': return t*33/80
    elif e.upper() == 'D': return 33 - t*11/50
    elif e.upper() == 'RO': return (t - 7.5)*22/35
    else: return t

def get_delisle(t, e):
    if e.upper() == 'F': return (212 - t)*5/6
    elif e.upper() == 'K': return (373.15 - t)*3/2
    elif e.upper() == 'C': return (100 - t)*3/2
    elif e.upper() == 'RA': return (671.67 - t)*5/6
    elif e.upper() == 'RE': return (80 - t)*15/8
    elif e.upper() == 'N': return (33 - t)*50/11
    elif e.upper() == 'RO': return (60 - t)*20/7
    else: return t

def get_romer(t, e):
    if e.upper() == 'F': return (t - 32)*7/24 + 7.5
    elif e.upper() == 'K': return (t - 273.15)*21/40 + 7.5
    elif e.upper() == 'C': return t*21/40 + 7.5
    elif e.upper() == 'RA': return (t - 491.67)*7/24 + 7.5
    elif e.upper() == 'RE': return t*21/32 + 7.5
    elif e.upper() == 'N': return t*35/22 + 7.5
    elif e.upper() == 'D': return 60 - t*7/20
    else: return t

temperatura = float(input("Temperatura: "))
escala = input("Escala: ")

print("Fahrenheit:", get_fahrenheit(temperatura, escala))
print("Kelvin:", get_kelvin(temperatura, escala))
print("Celsius:", get_celsius(temperatura, escala))
print("Réamour:", get_reamour(temperatura, escala))
print("Rankine:", get_rankine(temperatura, escala))
print("Newton:", get_newton(temperatura, escala))
print("Delisle:", get_delisle(temperatura, escala))
print("Rømer:", get_romer(temperatura, escala))
