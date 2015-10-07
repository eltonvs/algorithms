#!/usr/bin/env python
# -*- coding: UTF-8 -*-

dia = int(input("Digite o dia (DD): "))
mes = int(input("Digite o mês (MM): "))
ano = int(input("Digite o ano (AAAA): "))

#Verifica se a data informada está entre o intervalo que o algoritmo abrange
if ano >= 1900 and ano <= 2399:
	a = ano - 1900
	#Verifica se a data informada foi antes do dia 29 de fevereiro (em um ano bissexto)
	if dia <= 29 and mes <= 2 and (ano % 400 == 0 or (ano % 4 == 0 and ano % 100 != 0)):
		b = int((a/4)) - 1
	else:
		b = int(a/4)

	#Atribui o valor do mes a c
	if mes == 1 or mes == 10:
		c = 0
	elif mes == 5:
		c = 1
	elif mes == 8:
		c = 2
	elif mes == 2 or mes == 3 or mes == 11:
		c = 3
	elif mes == 7:
		c = 4
	elif mes == 9 or mes == 12:
		c = 5
	else:
		c = 6

	d = dia - 1
	diasemana = (a + b + c + d) % 7

	#Atribui o dia da semana de acordo com o resto da divisão
	if diasemana == 0:
		dia = "Segunda-Feira"
	elif diasemana == 1:
		dia = "Terça-Feira"
	elif diasemana == 2:
		dia = "Quarta-Feira"
	elif diasemana == 3:
		dia = "Quinta-Feira"
	elif diasemana == 4:
		dia = "Sexta-Feira"
	elif diasemana == 5:
		dia = "Sábado"
	else:
		dia = "Domingo"
	
	#Exibe o dia da semana
	print ("Dia da semana correspondente à data: ", dia)
else:
	print ("A data deve estar entre 1900 e 2399!")
