	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_clj_int                ## -- Begin function clj_int
	.p2align	4, 0x90
_clj_int:                               ## @clj_int
	.cfi_startproc
## %bb.0:
	movl	%edi, -4(%rsp)
	movl	%edi, %eax
	retq
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
