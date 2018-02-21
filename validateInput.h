#ifndef VALIDATEINPUT_H
#define VALIDATEINPUT_H

#include <stdio.h>
#include <stdbool.h>

/* Function stringCmp
 * Input: two strings to be compared
 * Output: bool, true if strings identical
 */
bool stringCmp(char *str1, char *str2);

/* Function printUsage
 * Input:
 * Output: prints Usage instructions to stdout
 */
void printUsage();

/* Function checkArgs
 * Input: argc from program parameters
 * Output: calls printUsage if not correct number of arguments
 */
void checkArgs(int argc);

/* Function checkOption
 * Input: argv from program parameters
 * Output: calls printUsage if mode not correctly specified
 */
char checkOption(char **argv);

/* Function openFile
 * Input: filename as string, char for what mode
 * Output: prints out error message if file could not be opened
 */
FILE *openFile(char *fileName,char *mode);

#endif