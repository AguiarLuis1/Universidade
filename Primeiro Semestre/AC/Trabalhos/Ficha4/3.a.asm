.data
.text
 	addi $s0,$0,0
 	addi $s1,$0,1
 loop:	slti $t0,$s1,1000
 	beq $t0,0,end
 	add $s2,$s2,$s1
 	sll $s1,$s1,1
 	j loop
 end:
 	li $v0,1
 	addi $a0,$s2,0
 	syscall
 	
