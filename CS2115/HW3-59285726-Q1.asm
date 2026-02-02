.text
	li $v0, 5
	syscall
	move $t0, $v0
	li $v0, 5
	syscall
	move $t1, $v0
	li $v0, 5
	syscall
	move $t2, $v0
	li $v0, 5
	syscall
	move $t3, $v0
	
	add $t4, $t0, $t1
	mult $t4, $t2
	mflo $t5
	and $t5, $t5, $t3
	
	li $v0, 1
	move $a0, $t5
	syscall
	
	li $v0, 10
	syscall
	
	
	
	