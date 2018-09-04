	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_createVars             ## -- Begin function createVars
	.p2align	4, 0x90
_createVars:                            ## @createVars
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$16, %eax
	movl	%eax, %edi
	callq	_malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_createNIL              ## -- Begin function createNIL
	.p2align	4, 0x90
_createNIL:                             ## @createNIL
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	callq	_createVars
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-8(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_createInteger          ## -- Begin function createInteger
	.p2align	4, 0x90
_createInteger:                         ## @createInteger
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	callq	_createVars
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	$1, (%rax)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdi
	movq	%rax, 8(%rdi)
	movq	-16(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_createFraction         ## -- Begin function createFraction
	.p2align	4, 0x90
_createFraction:                        ## @createFraction
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movsd	%xmm0, -8(%rbp)
	callq	_createVars
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	$2, (%rax)
	movsd	-8(%rbp), %xmm0         ## xmm0 = mem[0],zero
	movq	-16(%rbp), %rax
	movsd	%xmm0, 8(%rax)
	movq	-16(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_boolVars               ## -- Begin function boolVars
	.p2align	4, 0x90
_boolVars:                              ## @boolVars
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movb	%dil, %al
	andb	$1, %al
	movb	%al, -1(%rbp)
	callq	_createVars
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	$4, (%rax)
	movb	-1(%rbp), %cl
	movq	-16(%rbp), %rax
	andb	$1, %cl
	movb	%cl, 8(%rax)
	movq	-16(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_createString           ## -- Begin function createString
	.p2align	4, 0x90
_createString:                          ## @createString
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	callq	_createVars
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	$3, (%rax)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdi
	movq	%rax, 8(%rdi)
	movq	-16(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_createSymbol           ## -- Begin function createSymbol
	.p2align	4, 0x90
_createSymbol:                          ## @createSymbol
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	callq	_createVars
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	$5, (%rax)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdi
	movq	%rax, 8(%rdi)
	movq	-16(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
