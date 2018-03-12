#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct treeNode treeNode;
typedef struct label label;
typedef void (*freeLabelFunc)(void*);

/* Function treeNodeCreate
 * Input: Character as label
 * Output: pointer to a created treeNode;
 */
treeNode *treeNodeCreate(label *l);

/* Function binTreeGetChild
 * Input: pointer to parent treeNode and bool as index
 * Output: pointer to child treeNode
 */
treeNode *binTreeGetChild(treeNode *n, bool b);

/* Function binTreeSetChild
 * Input: pointer to parent treeNode, pointer to child treeNode, child index
 * Output:
 * Assigns the child node as the parents child. Sets leaf variable to false
 */
void binTreeSetChild(treeNode *parent, treeNode *child, bool b);

/* Function binTreeIsLeaf
 * Input: inspected treeNode
 * Output: true if inspected node is flagged as leaf
 */
 bool binTreeIsLeaf(treeNode *n);

/* Function binTreeHasLabel
 * Input: pointer to inspected treeNode
 * Output: bool, true if node has label
 */
bool binTreeHasLabel(treeNode *n);

/* Function binTreeSetLabel
 * Input: pointer to inspected treeNode
 * Output:
 */
 void binTreeSetLabel(treeNode *n, label *l);

/* Function binTreeGetLabel
 * Input: pointer to inspected treeNode
 * Output: pointer to label of given node
 */
label *binTreeGetLabel(treeNode *n);

/*Function binTreeJoinSubtrees
  * Input: two treeNodes acting as root of subtrees
  * Output new treeNode with given nodes as children
  */
treeNode *binTreeJoinSubtrees(treeNode *n1, treeNode *n2, label *l);

/* Function binTreeKill
 * Input: tree to be killed
 * Output:
 * Uses post order depth-first to free memory of each node in the tree
 */
void binTreeKill(treeNode *n, freeLabelFunc freeLabel);

#endif
