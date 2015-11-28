# -*- coding: utf-8 -*-
from os import system

global n, board

def clear_screen():
	system("clear")

def create_board():
	for i in range(n):
		board.append([])
		for j in range(n):
			board[i].append(ord(" "))

def show_board():
	clear_screen()
	for row in board:
		for i in range(n):
			print("|  %c %s" %(chr(row[i]), " |\n" if i == n-1 else " "), end='')

def check_winner(player):
	magic_sum = ord('X')*n if player == 1 else ord('O')*n

	for line in board:
		if sum(line) == magic_sum: return True

	for j in range(n):
		s = [board[i][j] for i in range(n)]
		if sum(s) == magic_sum: return True

	s = [board[i][i] for i in range(n)]
	if sum(s) == magic_sum: return True

	s = [board[i][n-i-1] for i in range(n)]
	if sum(s) == magic_sum: return True

	return False

def check_coord(x, y):
	if x not in range(0, n) or y not in range(0, n):
		return False
	if board[y][x] != ord(" "):
		return False
	return True

def do_move(player, x, y):
	board[y][x] = ord("X") if player == 1 else ord("O")

while True:
	clear_screen()

	n, board, player, alive = int(input("Digite o tamanho do tabuleiro: ")), [], 1, True

	create_board()

	for c in range(n**2):
		show_board()

		print("Jogador %i (%c), escola onde quer jogar:" %(player, "X" if player == 1 else "O"))
		while True:
			y, x = int(input("Linha: ")) - 1, int(input("Coluna: ")) - 1
			if check_coord(x, y): break
			print("As coodenadas digitadas foram imválidas, tente novamente:")

		do_move(player, x, y)

		if check_winner(player):
			show_board()
			print("O Jogador %i (%c) ganhou!" %(player, "X" if player == 1 else "O"))
			break
		if c == n**2-1:
			show_board()
			print("Houve um empate, o jogo deu velha!")
			break
		player = 2 if player == 1 else 1
	print("Fim do jogo")
	stay = int(input("Jogar novamente? [1 - Sim | 0 - Não] "))
	if stay == 0: break