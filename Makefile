CC = gcc
CFLAGS = -g -Wall

main:
	$(CC) $(CFLAGS) -o out/main.out src/main.c

run:
	out/main.out

clean:
	rm ./out/*.out -rf