include Makefile.inc

all: shellCodeModule shellDataModule

shellCodeModule:
	cd shellCodeModule; make

shellDataModule:
	printf "This is sample data." >> shellDataModule.bin && dd if=/dev/zero bs=1 count=1 >> shellDataModule.bin

clean:
	cd shellCodeModule; make clean
	rm -rf *.bin


.PHONY: shellCodeModule all clean
