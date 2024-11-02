CC=gcc
CFLAGS=-Wall -g
OBJ=shhs.o hash_md5.o hash_sha1.o hash_sha256.o hash_sha512.o
LIBS=-lssl -lcrypto

all: shhs

shhs: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c hash.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o shhs
