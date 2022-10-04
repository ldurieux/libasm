global ft_strcpy
extern ft_strlen

section .data
section .note.GNU-stack
section .text

ft_strcpy:
	cmp rdi, 0
	je .error
	cmp rsi, 0
	je .error

	; init vars
	mov rbx, rdi
	mov rdi, rsi
	mov r15, rbx
	; r15 = res, rbx = dst, rdi,rsi = src

	; check if src and dst are aligned
	mov r13, rbx
	and dil, 0x7
	and r13b, 0x7
	test dil, r13b
	jne .byte_copy_loop_head

	; align src and dst with 0
.align_ptr_loop_head:
	test rsi, 0x7
	je .aligned_prepare
	mov r14b, byte [rsi]
	mov byte [rbx], r14b
	inc rsi
	inc rbx
	cmp r14b, 0
	jne .align_ptr_loop_head

.aligned_prepare:
	mov rdi, rsi
	call ft_strlen
	add rax, rdi
	; rax = src_end

	; copy data 8 bytes at a time
.aligned_loop_head:
	mov r14, [rsi]
	add rsi, 8
	cmp rsi, rax
	jg .aligned_loop_tail
	mov [rbx], r14
	add rbx, 8
	jmp .aligned_loop_head

.aligned_loop_tail:
	sub rsi, 8

	; copy data 1 byte at a time
.byte_copy_loop_head:
	mov r14b, byte [rsi]
	mov byte [rbx], r14b
	inc rsi
	inc rbx
	cmp r14b, 0
	jne .byte_copy_loop_head
.end:
	mov rax, r15
	ret
.error:
	mov rax, 0
	ret
