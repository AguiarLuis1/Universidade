.data
.text 
	add $s0 $zero $zero
	addi $t0 $zero 1
	addi $t1 $zero 100
LABEL2:	beq $t0 $t1 LABEL1
	add $s0 $s0 $t0
	addi $t0 $t0 1
	j LABEL2
LABEL1:
	li $v0,1
	addi $a0,$s0,0
	syscall