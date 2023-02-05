#include <stdio.h>
#include <string.h>
#include "header.h"

#pragma warning(disable: 4996)


int outputRecord(char* argv) {

	char* cmdO = "-o";
	char* ptr = strstr(argv, cmdO);
	if (ptr != NULL) {

		removeSwitch(argv, 'o', '-');

	}

	bool loop = true;
	FILE* fp;
	char arrayHex[] = { 0 };
	char fileName[20];
	strcpy(fileName, argv);
	char* createAssembly = 0;
	char str[17] = { 0 };

	fp = fopen(argv, "r");

	if (fp == NULL) {

		printf("There is no file");

		return -1;
	}

	char dcByte[100] = { 0 };
	char enter[2] = { 0 };
	char* enter1 = "\n";

	int i = 0;

	while (fgets(str, sizeof(str), fp)) {


		createAssembly = readString(str, createAssembly);

		

	}

	// close the file 
	if (fclose(fp) != 0)
	{
		// the closing of the file failed
		printf("Can't close the TEXT file that we were writing to.\n");
		return -3;
	}

	return 0;
}