#ifndef DECODE_H
#define DECODE_H

#include "bitset.h"
#include "binaryTree.h"
#include "buildTree.h"


/* Function decode
 * Input: root treeNode of huffman tree, file pointers of input and output files
 * Output: writes decoded text to ouput file
 */
void decode(treeNode *root, FILE *in, FILE *out);

#endif
