.data
	string: .asciiz "My name is Tang Pok Man. My student ID is 59285726. My project name is "
	dot: .asciiz "."
	project: .space 20
.text
	li $v0, 8
	la $a0, project
	li $a1, 10
	syscall
	
	li $v0, 4
	la $a0, string
	syscall
	
	li $v0, 4
	la $a0, project
	syscall
	
	li $v0, 4
	la $a0, dot
	syscall
	
	li $v0, 10
	syscall