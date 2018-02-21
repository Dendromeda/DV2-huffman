#ifndef ENCODE_H
#define ENCODE_H

#include <stdio.h>
#include "binaryTree.h"
#include "list.h"
#include "bitset.h"
#include "frequencyAnalysis.h"
#include "buildTree.h"


/* Function encode
 * Input: root treeNode from huffman tree, file pointers to input 
 * and output files
 * Output: writes encoded data to output file
 */
void encode(treeNode *n, FILE *in, FILE *out);

/* Function addBitsets
 * Input: two bitset pointers
 * Output: The second bitset sequence is added at the end of the first bitset 
 */
void addBitsets(bitset *b1, bitset *b2);

/*Function buildBitset
 * Input: array of booleans of size CHAR_SET_SIZE, int as number of 
 * relevant elements
 * Output: created bitset from array
 */
bitset *buildBitset(list *l);

/* Function buildTable
 * Input: root treeNode of huffman tree
 * Output: array of bitset pointers acting as table, with array index as key
 * Uses depth-first traversing to find each leaf and add the sequence as abitset 
 * to the array
 */
bitset **buildTable(treeNode *n);

/* Function depthFirst
 * Input: node being inspected, list with bools signifying path, and array of
 * bitsets
 * Output: Stores sequences in bitset array at index of their corresponding 
 * char's ascii value
 */
void depthFirst(treeNode *n, list *l, bitset **arr);

void listRemoveEndNode(list *l);

#endif