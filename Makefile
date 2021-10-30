CC = gcc
CFLAGS = -g -Wall

main:
	mkdir out
	$(CC) $(CFLAGS) -o out/main.out src/main.c

run:
	out/main.out

clean:
	rm ./out/ -rf