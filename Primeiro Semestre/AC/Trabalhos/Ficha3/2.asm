.data
.text
main:
	li $s0,0#i
	li $s1,0#s
	li $t0,5
	beq $s0,5,end1
	sub $a0,$t0,$s0 #5-i
	addi $a1,$s0,0 #i
	jal funct
	add $s1,$s1,$v0
	addi $s0,$s0,1
end1:
	li $v0,1
	move $a0,$s1
	syscall
	li $v0,10
	syscall
funct: 
	addi $sp,$sp,-4
	sw $ra,0($sp)
	jal square 
	mul $t0,$v0,$a0
	move $a0,$a1
	jal square
	mul $t1,$v0,$a0
	sub $v0,$t0,$t1
	lw $ra, 0($sp)
	addi $sp,$sp,4
	jr $ra
square:
	mul $v0,$a0,$a0
	jr $ra 

