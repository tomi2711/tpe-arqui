GLOBAL load_idt
GLOBAL keyboard_handler
GLOBAL sti_enable
GLOBAL cli_enable
GLOBAL runInt80

EXTERN keyboard_handler_main

section .text

load_idt:
	lidt [rdi]
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

runInt80:
	int	80h
	ret
