CC=gcc
CFLAGS=-I. -o bin/fruityvm -std=c99


all:
	$(CC) $(CFLAGS) main.c vm.c 
	fruityvm