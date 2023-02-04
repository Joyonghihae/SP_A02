#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#pragma warning(disable: 4996)


const char* argumentArray(char* str, int argc);

int checkFilename(char* str);
int checkInputArgument(char* str);
int checkSrecArgument(char* str);

int checkTwoCommand(char* argv);
int checkOutputArgument(char* argv);


void help();