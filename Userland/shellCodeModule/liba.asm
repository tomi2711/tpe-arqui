GLOBAL clearScreen
GLOBAL printString

section .text

printString:
  mov rax, 'a'
  int 70h
  ret

clearScreen:
  int 90h
  ret
