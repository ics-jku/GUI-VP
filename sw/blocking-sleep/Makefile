override CC = riscv32-unknown-elf-gcc

CFLAGS  = -ggdb -march=rv32i -mabi=ilp32
ASFLAGS = $(CFLAGS)
LDFLAGS = -nostartfiles -Wl,--no-relax

all: main
main: main.o irq.o bootstrap.o
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $^
sim: main
	tiny32-vp --error-on-zero-traphandler=true --intercept-syscalls $<

.PHONY: all sim
