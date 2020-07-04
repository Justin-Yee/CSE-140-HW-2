CC=gcc
CFLAGS=-I.

make: MachineCode.o
	$(CC) -o MachineCode MachineCode.c
