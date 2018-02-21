#include "frequencyAnalysis.h"

/*Function frequencyAnalysis
 * Input: pointer to file being analysed
 * Output: array of int, ascii value of found character is the index and 
 * array value signifies frequency
 */
int *frequencyAnalysis(FILE *fp){
	int *arr = calloc(sizeof(int),CHAR_SET_SIZE);
	int c = getc(fp);
	
	for (int i = 0; i < 256; i++){
		arr[i] = 1;
	}
	
	while (c != EOF){
		int offsetC = c-CHAR_OFFSET;
		if (offsetC<CHAR_SET_SIZE)
			arr[offsetC]++;
		c = getc(fp);
	}
	arr[4]++;
	return arr;
}

/* Function printAnalysis
 * Input: array of int with size 256 from frequencyAnalysis
 * Output: prints out a table of ascii value of characters, characters 
 * and their frequency
 */
void printAnalysis(int *arr){
	for (int i = 0; i < CHAR_SET_SIZE; i++){
		printf("%-3d  %c: %d\n", i,i+CHAR_OFFSET,arr[i]);
	}
}