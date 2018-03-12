#include "binaryTree.h"


struct treeNode {
	label *label;
	bool leaf;
	treeNode *children[2];
};

/* Function treeNodeCreate
* Input: Character as label
* Output: pointer to a created treeNode;
*/
treeNode *treeNodeCreate(label *l){
	treeNode *n = malloc(sizeof(treeNode));
	n->label = l;
	n->leaf = 1;
	return n;
}

/* Function binTreeIsEmpty
 * Input: pointer to parent treeNode and index as bool
 * Output: pointer to child treeNode
 */
treeNode *binTreeGetChild(treeNode *n, bool b){
	return n->children[b];
}

/* Function binTreeSetChild
 * Input: pointer to parent treeNode, pointer to child treeNode, child index
 * Output:
 * Assigns the child node as the parents child. Sets leaf variable to false
 */
void binTreeSetChild(treeNode *parent, treeNode *child, bool b){
	parent->children[b] = child;
	parent->leaf = 0;
}

/* Function binTreeIsLeaf
 * Input: inspected treeNode
 * Output: true if inspected node is flagged as leaf
 */
 bool binTreeIsLeaf(treeNode *n){
	 if (n->leaf > 0){
		 return 1;
	 }
	 return 0;
 }

/* Function binTreeHasLabel
 * Input: pointer to inspected treeNode
 * Output: bool, true if node has label
 */
bool binTreeHasLabel(treeNode *n){
	return n->label != NULL;
}

/* Function binTreeSetLabel
 * Input: pointer to inspected treeNode
 * Output:
 */
void binTreeSetLabel(treeNode *n, label *l){
	 n->label = l;
 }

/* Function binTreeGetLabel
 * Input: pointer to inspected treeNode
 * Output: pointer to label of given node
 */
label *binTreeGetLabel(treeNode *n){
	 return n->label;
 }

 /*Function binTreeJoinSubtrees
  * Input: two treeNodes acting as root of subtrees, label
  * Output: new treeNode with given nodes as children and label added
  */
treeNode *binTreeJoinSubtrees(treeNode *n1, treeNode *n2, label *l){
	 treeNode *p = treeNodeCreate(l);
	 binTreeSetChild(p,n1,0);
	 binTreeSetChild(p,n2,1);
	 return p;
 }

/* Function binTreeKill
 * Input: tree to be killed
 * Output:
 * Uses post order depth-first to free memory of each node in the tree
 */
void binTreeKill(treeNode *n, freeLabelFunc freeLabel){
	if (binTreeHasLabel(n))
		freeLabel(binTreeGetLabel(n));
	if (!(binTreeIsLeaf(n))){
		binTreeKill(binTreeGetChild(n,0),freeLabel);
		binTreeKill(binTreeGetChild(n,1),freeLabel);
	}
	free(n);
}
