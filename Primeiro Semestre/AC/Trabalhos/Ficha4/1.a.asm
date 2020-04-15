#a)
.data
	msg: .asciiz "The final value is: "
.text
main: 	
	addi $s0,$0,0 #i=0
	addi $s1,$0,0 #s=0
loop:	slti $t0,$s0,10
	beq $t0,0,exit
	add $s1,$s1,$s0
	addi $s0,$s0,1
	j loop
exit:
	li $v0,4
	la $a0,msg
	syscall
	addi $a0,$s1,0
	jal printvalue
	#fim do programa(sem pseudo's)
	addi $v0,$0,10
	syscall
	
printvalue:
	addi $v0,$0, 1
	syscall
	jr $ra
