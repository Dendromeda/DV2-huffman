#ifndef DEBUG_H
#define DEBUG_H

void printError(char *str){
	FILE *fp = fopen("errorLog.txt","a");
	fprintf("%s\n",str);
	fclose("errorLog.txt");
}
#ifend