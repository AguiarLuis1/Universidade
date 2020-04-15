.text
.data
main:

fact_iter:
	li $t1,1	#$t0=i  pode usar-se registos temporarios porque nao é chamada outra função
	li $t0,$s0	#t1=s
loop:	beq $t1,$0, end
	mul $t1,$t1,$t0
	subi $t0,$t0,1
	j loop
end:	move $v0,$t1	#é devolvido á função o valor do registo de v0(sempre!)
	jr $ra
	

fact_recu:		#tem de se guardar na stack o valor de $ra e o valor de n
	bne $a0,$0,default
	li $v0,1
	jr $ra
default:	
	addi $sp,$sp,-8
	sw $ra,0($sp)
	sw $a0,4,($sp)
	addi $a0,$a0,-1
	jal fact_recu
	lw $a0,4($sp)
	mul $v0,$v0,$a0
	lw $ra,0($sp)
	addi $sp,$sp,8
	jr $ra
