CC=gcc
CFLAGS=-I.

make: MachineCode.o
	$(CC) -o MachineCode MachineCode.c

test: test.o
	$(CC) -o test test.c