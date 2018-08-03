	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_add_one                ## -- Begin function add_one
	.p2align	4, 0x90
_add_one:                               ## @add_one
	.cfi_startproc
## %bb.0:
                                        ## kill: def %edi killed %edi def %rdi
	movl	%edi, -4(%rsp)
	leal	1(%rdi), %eax
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$0, 4(%rsp)
	movl	$42, %edi
	callq	_add_one
	movl	%eax, %ecx
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	movl	%ecx, %esi
	callq	_printf
	xorl	%eax, %eax
	popq	%rcx
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"


.subsections_via_symbols
