CC = gcc
CFLAGS = -Wall -Wextra

all: mat jgrep move cpy print lf perm spec

mat: mat.c
	$(CC) $(CFLAGS) mat.c -o mat

jgrep: jgrep.c
	$(CC) $(CFLAGS) jgrep.c -o jgrep

move: move.c
	$(CC) $(CFLAGS) move.c -o move

cpy cpy.c:
	$(CC) $(CFLAGS) cpy.c -o cpy

print: print.c
	$(CC) $(CFLAGS) print.c -o print

lf: lf.c
	$(CC) $(CFLAGS) lf.c -o lf

perm: perm.c
	$(CC) $(CFLAGS) perm.c -o perm

spec: spec.c
	$(CC) $(CFLAGS) spec.c -o spec

clean:
	rm -f mat jgrep move cpy print lf perm spec

install: mat jgrep move cpy lf perm
	sudo cp mat jgrep move cpy print lf perm spec /usr/bin/
