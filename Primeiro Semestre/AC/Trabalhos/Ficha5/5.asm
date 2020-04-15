.data
lower:	.float	0.0
upper:	.float	300.0
step:	.float	20.0
cinco:	.float 	5.0
nove:	.float	9.0
trintedois:	.float 32.0
zero: 	.float 0.0
newline: .asciiz "\n"
space: .asciiz " "

.text
	
	lwc1 $f0,lower
	lwc1 $f1,upper
	lwc1 $f2,step
	lwc1 $f30,cinco
	lwc1 $f31,nove
	lwc1 $f29,trintedois
	lwc1 $f28,zero
	
	add.s $f3,$f0,$f28	#fahr=lower
loop:	c.lt.s $f1,$f3
	bc1t exit
	div.s $f4,$f30,$f31
	sub.s $f5,$f3,$f29
	mul.s $f6,$f4,$f5
	li $v0,2
	mov.s $f12,$f3
	syscall
	li $v0,4
	la $a0,space
	syscall
	li $v0,2
	mov.s $f12,$f6
	syscall
	li $v0,4
	la $a0,newline
	syscall
	add.s $f3,$f3,$f2
	j loop
exit:
	



