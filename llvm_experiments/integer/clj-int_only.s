	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	movq	_a@GOTPCREL(%rip), %rax
	movl	(%rax), %eax
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__const
	.globl	_a                      ## @a
	.weak_definition	_a
	.p2align	2
_a:
	.long	42                      ## 0x2a


.subsections_via_symbols
