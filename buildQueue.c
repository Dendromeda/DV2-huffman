

typedef struct label {
	char c;
	int frq;
};

/* Function qPriorityFunc
 * Input: two treeNode pointers to compare
 * Output: int signifying relation between the inspected values
 */
int qPriorityFunc(label l1, label l2){
	return (l1->frq)-(l2->frq);
}


/* Function createLabelArray
 * Input: array of int from frequencyAnalysis function in frequencyAnalysis.c
 * Output: array of pointers to labels
 */
label **createLabelArray(int *iArr){
	label **lArry = malloc(sizeof(label*)*256);
	for (int i = 0; i < 256; i++){
		lArry[i] = malloc(sizeof(label));
		lArry[i]->c = i;
		lArry[i]->frequency = iArr[i];
	}
	return lArry;
}
/* Function addLabel
 * Input: treeNode created by 
addLabel(treeNode *n)

/* Function buildQueue
 * Input: array of label pointers from createLabelArray
 * Output: priority queue with labels with frequency in rising order
 */
pqueue *buildQueue(label **lArry){
	pqueue *q = pqueue_empty(qPriorityFunc);
	
	
}