CC = gcc -std=c99
CFLAGS = -g -fno-omit-frame-pointer -Wall -Wextra

.PHONY: all
all: huffman
huffman: 
	$(CC) $(CFLAGS) -o $@ binaryTree.o bitset.o buildTree.o decode.o encode.o frequencyAnalysis.o list.o main.o pqueue.o validateInput.o

binaryTree.o:
	$(CC) $(CFLAGS) -c binaryTree.c
	
bitset.o:
	$(CC) $(CFLAGS) -c bitset.c
	
buildTree.o:
	$(CC) $(CFLAGS) -c buildTree.c
	
decode.o:
	$(CC) $(CFLAGS) -c decode.c
	
encode.o:
	$(CC) $(CFLAGS) -c encode.c
	
frequencyAnalysis.o:
	$(CC) $(CFLAGS) -c frequencyAnalysis.c
	
list.o:
	$(CC) $(CFLAGS) -c list.c
	
main.o:
	$(CC) $(CFLAGS) -c main.c
	
pqueue.o:
	$(CC) $(CFLAGS) -c pqueue.c
	
validateInput.o:
	$(CC) $(CFLAGS) -c validateInput.c
	