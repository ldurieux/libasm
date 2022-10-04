global ft_read
; linux
extern __errno_location
; OSX
; extern ___error

section .data
section .note.GNU-stack
section .text

ft_read:
	mov eax, 3
	mov rbx, rdi
	mov rcx, rsi
	int 80h
	; linux
	cmp rax, -4095
	jae .error
	; OSX
	; jc .error
	ret
.error:
	mov rbx, rax
	; linux
	xor rbx, -1	; rbx *= -1
	inc rbx
	call __errno_location
	; OSX
	; call ___error
	mov [rax], rbx
	mov rax, -1
	ret
