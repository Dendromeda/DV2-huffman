#ifndef FREQUENCYANALYSIS_H
#define FREQUENCYANALYSIS_H

#include <stdio.h>
#include <stdlib.h> 

#define CHAR_SET_SIZE 256
#define CHAR_OFFSET 0


/*Function frequencyAnalysis
 * Input: pointer to file being analysed
 * Output: array of int, ascii value of found character is the index and 
 * array value signifies frequency
 */
int *frequencyAnalysis(FILE *fp);

/* Function printAnalysis
 * Input: array of int with size 256 from frequencyAnalysis
 * Output: prints out a table of ascii value of characters, characters 
 * and their frequency
 */
void printAnalysis(int *arr);

#endif