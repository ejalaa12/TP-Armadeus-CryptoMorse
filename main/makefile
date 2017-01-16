CC = ~/Documents/tp-armadeus/armadeus/buildroot/output/host/usr/bin/arm-linux-gcc

all: main.c encrypt_func.c morse_func.c
	$(CC) -o main.o main.c encrypt_func.c morse_func.c -I.
	scp main.o root@172.20.13.45:/home/tp/main.o
