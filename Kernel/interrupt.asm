GLOBAL load_idt
GLOBAL keyboard_handler
GLOBAL sti_enable
GLOBAL cli_enable

EXTERN keyboard_handler_main

section .text

load_idt:
	push rbp
	mov	 rbp, rsp
	mov rdx, [rbp + 8]
	lidt [rdx]
	pop rbp
	ret

sti_enable:
	sti
	ret

cli_enable:
	cli
	ret

keyboard_handler:
  call    keyboard_handler_main
  iretq
