GLOBAL runSyscall

section .text

runSyscall:
    int 80h
    ret
