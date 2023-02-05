#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#pragma warning(disable: 4996)

int checkSrec(char* str);
int checkFileValidation(char* str);


int inputAssembly(char* argv);
void removeSwitch(char* str, char ch, char ch1);

char* readString(char* text, char* createAssembly);
int createFile(char* text, char* textName);



int outputRecord(char* argv);
char* readRecordData(char* str, char* createSREC);

void help();