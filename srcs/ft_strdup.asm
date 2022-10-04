global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc
; linux
extern __errno_location
; OSX
; extern ___error

section .data
section .note.GNU-stack
section .text

ft_strdup:
	cmp rdi, 0
	je .error

	mov rbx, rdi
	call ft_strlen

	mov rdi, rax
	inc rdi
	call malloc
	cmp rax, 0
	je .error

	mov rdi, rax
	mov rsi, rbx
	call ft_strcpy

	ret

.error:
	mov rax, 0
	ret
