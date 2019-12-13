

all: main 

main: main.c block.c block.h
	gcc -Wall main.c block.c -lcrypto -o ./main