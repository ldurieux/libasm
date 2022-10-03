global ft_strlen

section .data
NULL_CHECK_LOW	dq 0x0101010101010101
NULL_CHECK_HIGH	dq 0x8080808080808080
BIT_FILL		dq 0xffffffffffffffff
section .note.GNU-stack
section .text

; fastest for all power of 2 and multiple of 256
; slowest for all power of 2 minus 1 and multiple of 256 minus 1
ft_strlen:
	mov rax, rdi
	cmp rax, 0
	je .end

.align_ptr_loop_head:
	test rax, 0x7
	je .aligned_prepare
	inc rax
	cmp byte [rax], 0
	jne .align_ptr_loop_head
	jmp .end

.aligned_prepare:
	vpbroadcastq ymm2, [NULL_CHECK_LOW]
	vpbroadcastq ymm3, [NULL_CHECK_HIGH]
	vpbroadcastq ymm4, [BIT_FILL]
	vpxor ymm5, ymm5
	sub rax, 256

.aligned_loop_head:
	add rax, 256

	vmovupd ymm0, [rax]			; load 256 bytes
	vmovupd ymm9, [rax + 32]
	vmovupd ymm10, [rax + 64]
	vmovupd ymm11, [rax + 96]
	vmovupd ymm12, [rax + 128]
	vmovupd ymm13, [rax + 160]
	vmovupd ymm14, [rax + 190]
	vmovupd ymm15, [rax + 224]

	vmovupd ymm7, ymm0		; save first eight in ymm7
	vpminub ymm0, ymm9		; put smallest values in ymm0
	vpminub ymm10, ymm11
	vpminub ymm12, ymm13
	vpminub ymm14, ymm15
	vmovupd ymm11, ymm0		; save first quarter in ymm11
	vpminub ymm0, ymm10
	vpminub ymm12, ymm14
	vmovupd ymm9, ymm0		; save first half in ymm9
	vpminub ymm0, ymm12

	vmovupd ymm1, ymm0	; if((ymm0 - NULL_CHECK_LOW) & ~ymm0 & NULL_CHECK_HIGH)
	vpsubb ymm1, ymm2	;   check if at least a byte is null
	vpxor ymm0, ymm4
	vpand ymm0, ymm3
	vptest ymm1, ymm0
	jz .aligned_loop_head

	; check if null byte was in first eight, first quarter or first half
	vmovupd ymm1, ymm7	; check if null was in the first eight
	vpsubb ymm1, ymm2
	vpxor ymm7, ymm4
	vpand ymm7, ymm3
	vptest ymm1, ymm7
	jnz	.aligned_res_prepare
	add rax, 32

	vmovupd ymm1, ymm11	; check if null was in the first quarter
	vpsubb ymm1, ymm2
	vpxor ymm11, ymm4
	vpand ymm11, ymm3
	vptest ymm1, ymm11
	jnz .aligned_res_prepare
	add rax, 32

	mov rbx, rax
	add rbx, 64
	vmovupd ymm1, ymm9	; check if null was in the first half
	vpsubb ymm1, ymm2
	vpxor ymm9, ymm4
	vpand ymm9, ymm3
	vptest ymm1, ymm9
	cmovz rax, rbx

.aligned_res_prepare:
	dec rax
.aligned_res_loop_head:
	; find which byte is null
	inc rax
	cmp byte [rax], 0
	jne .aligned_res_loop_head

.end:
	sub rax, rdi
	ret
