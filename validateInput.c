#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Function stringCmp
 * Input: two strings to be compared
 * Output: bool, true if strings are identical
 */
bool stringcmp(char *str1, char *str2){
	int i = 0;
	while(str1[i]){
		if (str1[i] != str2[i]){
			return 0;
		}
		i++;
	}
	if (str2[i]){
		return 0;
	}
	return 1;
}

/* Function printUsage
 * Input:
 * Output: prints Usage instructions to stdout
 */
void printUsage(){
	printf("USAGE:\nhuffman [OPTION] [FILE0] [FILE1] [FILE2]\nOptions:\n");
	printf("-encode encodes FILE1 according to frequence analysis done on");
	printf(" FILE0. Stores the result in FILE2\n-decode decodes FILE1 ");
	printf("according to frequence analysis done on FILE0. Stores the ");
	printf("result in FILE2\n");
}

/* Function checkArgs
 * Input: argc from program parameters
 * Output: calls printUsage if not correct number of arguments
 */
void checkArgs(int argc){
	if (argc != 5){
		printUsage();
		exit(0);
	}
}

/* Function checkOption
 * Input: argv from program parameters
 * Output: calls printUsage if mode not correctly specified
 */
bool checkOption(char **argv){
	char *op = argv[1];
	char *e = "-encode";
	char *d = "-decode";
	if (stringcmp(op,e))
		return 0;
	if (stringcmp(op,d))
		return 1;
	return NULL;
}

/* Function openFile
 * Input: filename as string, char for what mode
 * Output: prints out error message if file could not be opened
 */
FILE *openFile(char *fileName,char *mode){
	FILE *fp;
	fp = fopen(fileName, mode);
	if (fp == NULL){
		fprintf(stderr, "ERROR - COULD NOT OPEN FILE '%s'",fileName);
		exit(0);
	}
	return fp;
}
