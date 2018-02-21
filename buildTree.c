
#include "buildTree.h"

//DEBUG
void printQueue(treeNode *n){
	char c = binTreeGetLabel(n)->c;
	int frq = binTreeGetLabel(n)->frq;
	printf("%c : %-3d\n", c, frq);
}



/* Function qPriorityFunc
 * Input: two treeNode pointers to compare
 * Output: int signifying relation between the inspected values
 */
int qPriorityFunc(void *n0, void *n1){
	int v0 = binTreeGetLabel(n0)->frq;
	int v1 = binTreeGetLabel(n1)->frq;
	return v0 - v1;
}


/* Function createNodeArray
 * Input: array of int from frequencyAnalysis function in frequencyAnalysis.c
 * Output: array of pointers to created treeNodes
 */
treeNode **createNodeArray(int *iArr){
	treeNode **nArr = malloc(sizeof(treeNode*)*CHAR_SET_SIZE);
	for (int i = 0; i < CHAR_SET_SIZE; i++){
		label *l = malloc(sizeof(label));
		l->c = i+CHAR_OFFSET;
		l->frq = iArr[i];
		treeNode *n = treeNodeCreate(l);
		nArr[i] = n;
	}
	return nArr;
}

/* Function addLabels
 * Input: node created by joinSubTrees in binaryTrees.c
 * Output:
 * Creates a new label and sets the frequency value to the sum of its childrens'
 * frequency values 
 */
label *addedLabel(treeNode *n0, treeNode *n1){
	int v0 = binTreeGetLabel(n0)->frq;
	int v1 = binTreeGetLabel(n1)->frq;
	label *l = malloc(sizeof(label));
	l->c = BRANCH_VALUE;
	l->frq = v0 + v1;
	return l;
}

/* Function buildQueue
 * Input: array of label pointers from createLabelArray
 * Output: priority queue with labels with frequency in rising order
 */
pqueue *buildQueue(treeNode **nArr){
	cmp_func func = *qPriorityFunc;
	pqueue *q = pqueue_empty(func);
	for (int i = 0; i < CHAR_SET_SIZE;i++){
		pqueue_insert(q, nArr[i]);
	}
	return q;
}

/* Function buildHuffmanTree
 * Input: int array from frequencyAnalysis function
 * Output: treeNode now root of huffman tree
 * Will use the functions specified in this file to create a priority queue
 * Will go through newly created queue of nodes and join the two nodes with 
 * lowest frequency, and use addLabel to give the new created root node a 
 * label with frequency value set to the sum of child nodes using addLabel
 */
treeNode *buildHuffmanTree(int *iArr){
	
	treeNode **nArr = createNodeArray(iArr);
	pqueue *q = buildQueue(nArr);
	
	//pqueue_print(q, (*printQueue));
	treeNode *n0 = pqueue_inspect_first(q);
	pqueue_delete_first(q);
	treeNode *n1;
	treeNode *r;
	label *l;
	while (!pqueue_is_empty(q)){
		n1 = pqueue_inspect_first(q);
		pqueue_delete_first(q);
		l = addedLabel(n0, n1);
		r = binTreeJoinSubtrees(n0, n1, l);
		pqueue_insert(q, r);
		n0 = pqueue_inspect_first(q);
		pqueue_delete_first(q);
	}
	pqueue_kill(q);
	free(nArr);
	
	return n0;
}