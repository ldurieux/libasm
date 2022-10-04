global ft_write

section .data
section .note.GNU-stack
section .text

ft_write:
	mov eax, 4
	mov ebx, edi
	mov rcx, rsi
	int 80h
	ret
