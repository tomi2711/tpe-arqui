GLOBAL kout
GLOBAL kin

section .text

;------------------------------------------------------------------------
; void kout(unsigned short port, unsigned char data);
; Outputs the data to the port
;------------------------------------------------------------------------

kout:
	mov rax, 0x0
	mov rdx, 0x0

	mov ax, si
	and ax, 0xFF
	mov dx, di
	out dx, al

	ret

;------------------------------------------------------------------------
; unsigned char kin(unsigned short port);
; Returns the input of the port
;------------------------------------------------------------------------

kin:
	;push	rbp
	;mov		rbp, rsp

	;mov	rax, 0x0000	; clears eax
	mov	dx, di
	in	al, dx

	;pop		rbp
	ret
