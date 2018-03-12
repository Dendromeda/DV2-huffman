CC = gcc -std=c99
CFLAGS = -g -fno-omit-frame-pointer -Wall -Wextra

.PHONY: all
all: huffman
huffman: binaryTree.o bitset.o buildTree.o decode.o encode.o frequencyAnalysis.o list.o huffman.o pqueue.o validateInput.o
	$(CC) $(CFLAGS) -o $@ binaryTree.o bitset.o buildTree.o decode.o encode.o frequencyAnalysis.o list.o huffman.o pqueue.o validateInput.o

binaryTree.o: binaryTree.c binaryTree.h
	$(CC) $(CFLAGS) -c binaryTree.c

bitset.o: bitset.c bitset.h
	$(CC) $(CFLAGS) -c bitset.c

buildTree.o: buildTree.c buildTree.h
	$(CC) $(CFLAGS) -c buildTree.c

decode.o: decode.c decode.h
	$(CC) $(CFLAGS) -c decode.c

encode.o: encode.c encode.h
	$(CC) $(CFLAGS) -c encode.c

frequencyAnalysis.o: frequencyAnalysis.c frequencyAnalysis.h
	$(CC) $(CFLAGS) -c frequencyAnalysis.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

huffman.o: huffman.c
	$(CC) $(CFLAGS) -c huffman.c

pqueue.o: pqueue.c pqueue.h
	$(CC) $(CFLAGS) -c pqueue.c

validateInput.o: validateInput.c validateInput.h
	$(CC) $(CFLAGS) -c validateInput.c

.PHONY: clean
clean:
	rm -fv *.o huffman
