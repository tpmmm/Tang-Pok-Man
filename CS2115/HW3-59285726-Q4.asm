.data
	h: .asciiz "h("
	bracket: .asciiz ") = "
	newLine: .asciiz "\n"

.text
	li $s0, 0	
	while:
		beq $s0, 31, exit
		addi $s1, $s0, 0

		li $v0, 4
		la $a0, h
		syscall
	
		li $v0, 1
		move $a0, $s0
		syscall
	
		li $v0, 4
		la $a0, bracket
		syscall
	
		jal calculate
		move $a0, $v0
		li $v0, 1
		syscall
	
		li $v0, 4
		la $a0, newLine
		syscall
	
		addi $s0, $s1, 0
		addi $s0, $s0, 1
		j while
	
		exit:
			li $v0,10
			syscall

	calculate:
		beq $s0, 0, zero
		beq $s0, 1, one
		beq $s0, 2, two
		beq $s0, 3, three
		beq $s0, 4, four
		beq $s0, 5, five
		beq $s0, 6, six
		beq $s0, 7, seven
	
		addi $sp, $sp, -20
		sw $ra, ($sp)
		sw $s0, 16($sp)
	
		addi $s0, $s0, -1
		jal calculate
		sw $v0, 4($sp)
		lw $s0, 16($sp)
	
		addi $s0, $s0, -2
		jal calculate
		sw $v0, 8($sp)
		lw $s0, 16($sp)
	
		addi $s0, $s0, -3
		jal calculate
		sw $v0, 12($sp)
		
		lw $ra, ($sp)
		lw $t0, 4($sp)
		lw $t1, 8($sp)
		lw $t3, 12($sp)
		add $t0, $t0, $t1
		sub $v0, $t0, $t3
		add $sp, $sp, 20
		jr $ra
	
	zero:
		li $v0, 5
		jr $ra
		
	one:
		li $v0, 9
		jr $ra
		
	two:
		li $v0, 2
		jr $ra
		
	three:
		li $v0, 8
		jr $ra
		
	four:
		li $v0, 5
		jr $ra
		
	five:
		li $v0, 7
		jr $ra
		
	six:
		li $v0, 2
		jr $ra
		
	seven:
		li $v0, 6
		jr $ra
