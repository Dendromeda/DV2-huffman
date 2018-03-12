#include "encode.h"

/* Function encode
 * Input: root treeNode from huffman tree, file pointers to input
 * and output files
 * Output: writes encoded data to output file
 */
void encode(treeNode *n, FILE *in, FILE *out){
	bitset **arr = buildTable(n);

	int c = fgetc(in);
	int j = 0;
	bool b;
	bitset *charBSet = arr[c];
	bitset *bSet = bitset_empty();
	while (c != EOF){
		for (int i = 7; i >= 0; i--){
			// Internal loop runs for each character written to output file
			b = bitset_memberOf(charBSet, j);
			bitset_setBitValue(bSet, i, b);
			j++;
			//If input character bitsequence is done,reads new character
			if (j >= bitset_size(charBSet)){
				j = 0;
				c = fgetc(in);
				// If new file is EOF, exits internal loop
				if (c != EOF){
					charBSet = arr[c];
				}

			}
		}
		fprintf(out, "%s", bitset_toByteArray(bSet));
	}
	for (int i = 0; i < CHAR_SET_SIZE; i++){
		bitset_free(arr[i]);
	}
	free(arr);
}

/*Function buildBitset
 * Input: array of booleans of size CHAR_SET_SIZE, int as number of
 * relevant elements
 * Output: created bitset from array
 */
bitset *buildBitset(list *l){
	list_pos pos = list_first(l);
	bitset *seq = bitset_empty();
	bool *b;
	while (!list_is_end(l, pos)){
		b = list_inspect(l,pos);
		bitset_setBitValue(seq, bitset_size(seq), *b);
		pos = list_next(l, pos);
	}
	return seq;
}

/* Function buildTable
 * Input: root treeNode of huffman tree
 * Output: array of bitset pointers acting as table, with array index as key
 * Uses depth-first traversing to find each leaf and add the sequence as abitset
 * to the array
 */
bitset **buildTable(treeNode *n){
	list *l = list_empty();
	bitset **bitsetArray = malloc(sizeof(bitset)*CHAR_SET_SIZE);
	depthFirst(n, l, bitsetArray);
	binTreeKill(n, *free);
	list_kill(l);
	return bitsetArray;
}

void depthFirst(treeNode *n, list *l, bitset **arr){

	if (binTreeIsLeaf(n)){
		int c = binTreeGetLabel(n)->c;
		arr[c-CHAR_OFFSET] = buildBitset(l);
		return;
	}
	bool b = 0;
	list_insert(l, list_end(l), &b);
	depthFirst(binTreeGetChild(n, 0), l, arr);
	b = 1;
	depthFirst(binTreeGetChild(n, 1), l, arr);
	listRemoveEndNode(l);
}


/* Function listRemoveEndNode
 * Input: List to be altered
 * Output:
 */
void listRemoveEndNode(list *l){
	if (list_is_empty(l)){
		return;
	}
	list_pos pos = list_first(l);
	while (!list_is_end(l, list_next(l, pos))){
		pos = list_next(l, pos);
	}
	list_remove(l, pos);
}
