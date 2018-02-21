#include <stdio.h>
#include "validateInput.h"
#include "binaryTree.h"
#include "frequencyAnalysis.h"
#include "buildTree.h"
#include "encode.h"
#include "decode.h"


void depthfirst(treeNode *n, char *arr, int parentpos, int childpos);

int main(int argc, char **argv){
	checkArgs(argc);
	bool mode = checkOption(argv);
	FILE *key = openFile(argv[2],"rb");
	FILE *inFile = openFile(argv[3], "rb");
	FILE *outFile = openFile(argv[4], "wb");
	
	
	int *frqArr = frequencyAnalysis(key);
	treeNode *hfmTree = buildHuffmanTree(frqArr);
	free(frqArr);
	
	
	if (mode){
		decode(hfmTree, inFile, outFile);
		printf("File decoded succesfully.");
	}
	else {
		encode(hfmTree, inFile, outFile);
		printf("%ld bytes read from %s\n", ftell(inFile), argv[3]);
		printf("%ld used in encoded form.", ftell(outFile));
	}
	fclose(key);
	fclose(inFile);
	fclose(outFile);
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
/*	FILE *fp = openFile("testfile.txt","r");
	FILE *out = openFile("output.txt", "w");
	int *iArr = frequencyAnalysis(fp);
	printAnalysis(iArr);
	fclose(fp);
	fp = openFile("testfile.txt","r");
	treeNode *r = buildHuffmanTree(iArr);
	char *arr = calloc(sizeof(char),64);
	depthfirst(r, arr, 0, 0);
	for (int i = 0; i < 64; i++){
		printf("%-3d:  %c\n",i,arr[i]);
	}
	encode(r, fp, out);
}

void depthfirst(treeNode *n, char *arr, int parentpos, int childpos){
	int pos = 2*parentpos+childpos;
	if (!binTreeIsLeaf(n)){
		depthfirst(binTreeGetChild(n, 0), arr, pos, 1);
		depthfirst(binTreeGetChild(n, 1), arr, pos, 2);
	}
	arr[pos] = binTreeGetLabel(n)->c;
} */