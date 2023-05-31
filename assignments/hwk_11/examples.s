	.file	"examples.c"
	.text
	.globl	absdiff
	.type	absdiff, @function
absdiff:
.LFB39:
	.cfi_startproc
	endbr64
	cmpq	%rsi, %rdi
	jge	.L2
	addq	$1, lt_cnt(%rip)
	movq	%rsi, %rax
	subq	%rdi, %rax
	ret
.L2:
	addq	$1, ge_cnt(%rip)
	movq	%rdi, %rax
	subq	%rsi, %rax
	ret
	.cfi_endproc
.LFE39:
	.size	absdiff, .-absdiff
	.globl	absdiff_succinct
	.type	absdiff_succinct, @function
absdiff_succinct:
.LFB40:
	.cfi_startproc
	endbr64
	cmpq	%rsi, %rdi
	jge	.L5
	movq	%rsi, %rax
	subq	%rdi, %rax
	ret
.L5:
	movq	%rdi, %rax
	subq	%rsi, %rax
	ret
	.cfi_endproc
.LFE40:
	.size	absdiff_succinct, .-absdiff_succinct
	.globl	factorial_do_while
	.type	factorial_do_while, @function
factorial_do_while:
.LFB41:
	.cfi_startproc
	endbr64
	movl	$1, %eax
.L8:
	imulq	%rdi, %rax
	subq	$1, %rdi
	cmpq	$1, %rdi
	jg	.L8
	ret
	.cfi_endproc
.LFE41:
	.size	factorial_do_while, .-factorial_do_while
	.globl	factorial_while
	.type	factorial_while, @function
factorial_while:
.LFB42:
	.cfi_startproc
	endbr64
	movl	$1, %eax
	jmp	.L10
.L11:
	imulq	%rdi, %rax
	subq	$1, %rdi
.L10:
	cmpq	$1, %rdi
	jg	.L11
	ret
	.cfi_endproc
.LFE42:
	.size	factorial_while, .-factorial_while
	.globl	factorial_for
	.type	factorial_for, @function
factorial_for:
.LFB43:
	.cfi_startproc
	endbr64
	movl	$1, %edx
	movl	$2, %eax
	jmp	.L13
.L14:
	imulq	%rax, %rdx
	addq	$1, %rax
.L13:
	cmpq	%rdi, %rax
	jle	.L14
	movq	%rdx, %rax
	ret
	.cfi_endproc
.LFE43:
	.size	factorial_for, .-factorial_for
	.globl	switch_example
	.type	switch_example, @function
switch_example:
.LFB44:
	.cfi_startproc
	endbr64
	subq	$100, %rsi
	cmpq	$6, %rsi
	ja	.L22
	leaq	.L18(%rip), %rcx
	movslq	(%rcx,%rsi,4), %rax
	addq	%rcx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L18:
	.long	.L21-.L18
	.long	.L22-.L18
	.long	.L20-.L18
	.long	.L19-.L18
	.long	.L17-.L18
	.long	.L22-.L18
	.long	.L17-.L18
	.text
.L21:
	leaq	(%rdi,%rdi,2), %rax
	leaq	(%rdi,%rax,4), %rdi
	jmp	.L16
.L20:
	addq	$10, %rdi
.L19:
	addq	$11, %rdi
.L16:
	movq	%rdi, (%rdx)
	ret
.L17:
	imulq	%rdi, %rdi
	jmp	.L16
.L22:
	movl	$0, %edi
	jmp	.L16
	.cfi_endproc
.LFE44:
	.size	switch_example, .-switch_example
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"Insufficient arguments. Expected 3 integer inputs."
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"%li\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB45:
	.cfi_startproc
	endbr64
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$24, %rsp
	.cfi_def_cfa_offset 64
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	cmpl	$3, %edi
	jle	.L28
	movq	%rsi, %rbp
	movq	8(%rsi), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol@PLT
	movq	%rax, %rbx
	movq	16(%rbp), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol@PLT
	movq	%rax, %r12
	movq	24(%rbp), %rdi
	movl	$10, %edx
	movl	$0, %esi
	call	strtol@PLT
	movq	%rax, %r13
	movq	%r12, %rsi
	movq	%rbx, %rdi
	call	absdiff
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rbp
	movq	%rbp, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movq	%r12, %rsi
	movq	%rbx, %rdi
	call	absdiff_succinct
	movq	%rax, %rdx
	movq	%rbp, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movq	%rbx, %rdi
	call	factorial_do_while
	movq	%rax, %rdx
	movq	%rbp, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movq	%rbx, %rdi
	call	factorial_while
	movq	%rax, %rdx
	movq	%rbp, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movq	%rbx, %rdi
	call	factorial_for
	movq	%rax, %rdx
	movq	%rbp, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movq	%rsp, %rdx
	movq	%r13, %rsi
	movq	%rbx, %rdi
	call	switch_example
	movq	(%rsp), %rdx
	movq	%rbp, %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$0, %eax
.L23:
	movq	8(%rsp), %rdx
	subq	%fs:40, %rdx
	jne	.L29
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
.L28:
	.cfi_restore_state
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	$-1, %eax
	jmp	.L23
.L29:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE45:
	.size	main, .-main
	.globl	ge_cnt
	.bss
	.align 8
	.type	ge_cnt, @object
	.size	ge_cnt, 8
ge_cnt:
	.zero	8
	.globl	lt_cnt
	.align 8
	.type	lt_cnt, @object
	.size	lt_cnt, 8
lt_cnt:
	.zero	8
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
