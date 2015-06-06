include ../Makefile.inc

MODULE=shellCodeModule.bin
SOURCES=$(wildcard *.c)
SOURCES_ASM=$(wildcard *.asm)
OBJECTS=$(SOURCES:.c=.o)
OBJECTS_ASM=$(SOURCES_ASM:.asm=.o)

all: $(MODULE)

$(MODULE): $(OBJECTS) $(OBJECTS_ASM)
	$(LD) $(LDFLAGS) -T shellCodeModule.ld $(OBJECTS) $(OBJECTS_ASM) -o  ../$(MODULE)

%.o: %.c
	$(GCC) $(GCCFLAGS) -I./include -c $< -o $@

%.o : %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm -rf *.o

.PHONY: all clean
