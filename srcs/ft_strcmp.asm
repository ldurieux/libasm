global ft_strcmp

section .data
section .note.GNU-stack
section .text

ft_strcmp:
	cmp rdi, 0
	je .error
	cmp rsi, 0
	je .error
	xor r13d, r13d

.loop_head:
	mov r12b, byte [rdi]
	mov r13b, byte [rsi]
	cmp r12b, 0
	je .loop_tail
	inc rdi
	inc rsi
	cmp r12b, r13b
	je .loop_head
.loop_tail:

	xor eax, eax
	mov al, r12b
	sub eax, r13d
	ret
.error:
	mov rax, rdi
	sub rax, rsi
	ret
