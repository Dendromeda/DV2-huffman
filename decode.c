#include "decode.h"

/* Function convertToBitset
 * Input: character to be converted
 * Output: bitset with converted bitsequence
 */
bitset *convertToBitset(int c){
	bitset *b = bitset_empty();
	int d = 128;
	for (int i = 0; i < 8; i++){
		bitset_setBitValue(b, i, (bool)c/d);
		c = c%d;
		d = d/2;
	}
	return b;
}

/* Function decode
 * Input: root treeNode of huffman tree, file pointers of input and output files
 * Output: writes decoded text to ouput file
 */
void decode(treeNode *root, FILE *in, FILE *out){
	treeNode *n = root;
		int c = fgetc(in);
	while (c != EOF){
		int d = 128;
		for (int j = 0; j < 8; j++){
			bool b = c&d;
			n = binTreeGetChild(n, b);
			if (binTreeIsLeaf(n)){
				fputc(binTreeGetLabel(n)->c, out);
				n = root;
			}
			d = d/2;
		}
		c = fgetc(in);
	}
	binTreeKill(root, *free);
}