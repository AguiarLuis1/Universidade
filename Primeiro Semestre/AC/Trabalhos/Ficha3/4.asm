.data
.text
main:
li $v0,5
syscall
move $a0,$v0
li $v0,5
syscall
move $a1,$v0
jal pow
move $a0,$v0
li $v0,1
syscall
li $v0,10
syscall

pow: addi $sp,$sp,-4
	sw $ra,0($sp)	
bne $a1,0,dft
	li $v0,1
	jr $ra
	
dft:	
	addi $a1,$a1,-1
	jal pow
	mul $v0,$v0,$a0
	lw $ra, 0($sp)
	addi $sp,$sp,4
	jr $ra 
