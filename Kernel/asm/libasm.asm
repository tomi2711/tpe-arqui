GLOBAL cpuVendor
GLOBAL kin
GLOBAL kout

section .text

cpuVendor:
	push rbp
	mov rbp, rsp

	push rbx

	mov rax, 0
	cpuid


	mov [rdi], ebx
	mov [rdi + 4], edx
	mov [rdi + 8], ecx

	mov byte [rdi+13], 0

	mov rax, rdi

	pop rbx

	mov rsp, rbp
	pop rbp
	ret

kin:
	mov	dx, di
	in	al, dx

	ret

kout:
	mov rax, 0x0
	mov rdx, 0x0

	mov ax, si
	and ax, 0xFF
	mov dx, di
	out dx, al

	ret
