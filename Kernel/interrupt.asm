GLOBAL kEnableInterrupts
GLOBAL kDisableInterrupts
GLOBAL kSetHandler
GLOBAL kGetIDTR

GLOBAL keyboardInterruptHandler

EXTERN keyboardHandler

section .text

kEnableInterrupts:
	sti
	ret

kDisableInterrupts:
	cli
	ret

kGetIDTR:
	sidt [rdi]
	ret

kSetHandler:

	mov rax, rsi

	shl rdi, 4			; quickly multiply rdi by 16 to go to the corresponding place in the table
	add rdi, rdx		; adds the base address of the idt table to the place in the table
	stosw						; store the low word (15..0)
	shr rax, 16
	add rdi, 4			; skip the gate marker
	stosw						; store the high word (31..16)
	shr rax, 16
	stosd						; store the high dword (63..32)

	ret

; Handlers

keyboardInterruptHandler:
	pushaq
  call    keyboardHandler
	mov al, 0x20
	out 0x20, al
	popaq
  iretq
