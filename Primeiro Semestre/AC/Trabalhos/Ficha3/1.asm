.data
	msg: .asciiz "O valor final e:"
.text

main: 	addi $s0,$0,0#i=0
	addi $s1,$0,0#s=0
loop:	beq $s0,10,end
	addi $a0,$s0,0 #i
	addi $a1,$s0,1 #i+1
	jal sumsquare
	add $s1,$v1,$s1
	addi $s0,$s0,1
	j loop

end:	li $v0,4
	la $a0,msg
	syscall
	li $v0,1
	addi $a0,$s1,0
	syscall
	li $v0,10
	syscall

sumsquare:
	mul $t0,$a0,$a0
	mul $t1,$a1,$a1
	add $v1,$t0,$t1
	jr $ra