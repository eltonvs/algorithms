.data
	str1:	.asciiz "Enter the first number: "
	str2:	.asciiz "Enter the second number: "
	str3:	.asciiz "The result is: "
.text
.globl main

main:
	addi $t0, $zero, 100

	#Print str1
	li $v0, 4
	la $a0, str1
	syscall

	#Get integer
	li $v0, 5
	syscall
	move $t0, $v0

	#Print str2
	li $v0, 4
	la $a0, str2
	syscall

	#Get integer
	li $v0, 5
	syscall
	move $t1, $v0

	#Make sum
	sub $s0, $t0, $t1

	#Print str3
	li $v0, 4
	la $a0, str3
	syscall

	#Print result
	li $v0, 1
	move $a0, $s0
	syscall
