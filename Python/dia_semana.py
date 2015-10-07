#!/usr/bin/env python
# -*- coding: UTF-8 -*-

def dia_semana(dia, mes, ano):
    dias_semana = ["Segunda-Feira", "Terça-Feira", "Quarta-Feira", "Quinta-Feira", "Sexta-Feira", "Sábado", "Domingo"]

    #Verifica se a data informada está entre o intervalo que o algoritmo abrange
    if ano not in range(1900, 2400):
        print("A data deve estar entre 1900 e 2399!")
        return 0

    #Conta quantos anos se passaram de 1900 até 'ano'
    a = ano - 1900
    #Recebe o número de anos bissextos de 1900 até 'ano'
    b = int(a/4)
    #Se a data informada foi antes do dia 29/02 de um ano bissexto, diminiu 1 de b
    if dia <= 29 and mes <= 2 and (ano%400 == 0 or (ano%4 == 0 and ano%100 != 0)): b -= 1

    #Atribui o valor do mes a c
    if mes in [1, 10]: c = 0
    elif mes == 5: c = 1
    elif mes == 8: c = 2
    elif mes in [2, 3, 11]: c = 3
    elif mes == 6: c = 4
    elif mes in [9, 12]: c = 5
    else: c = 6

    d = dia - 1
    rd = (a + b + c + d)%7

    #Exibe o dia da semana de acordo com o resto da divisão 'rd'
    print(dias_semana[rd])

d = int(input("Digite o dia (DD): "))
m = int(input("Digite o mês (MM): "))
a = int(input("Digite o ano (AAAA): "))

dia_semana(d, m, a)
