#include <stdio.h>
#include <string.h>
#include "header.h"

#pragma warning(disable: 4996)


int inputAssembly(char* argv) {


	// -iddd.dat 이렇게 입력

	// 1. -i제거하기 
	char* cmdI = "-i";
	char* ptr = strstr(argv, cmdI);
	if (ptr != NULL) {

		removeSwitch(argv, 'i', '-');

	}


	//1.  dc.b는 한줄씩 계속 반복해서 붙이기
	//2. 이거.. 16진수인가 뭐야이거 음 $해서..음음음 아놔 
	// 2자리 16진수로 표시 
	// 각라인은 최대 16캐릭터만 표시가능 

	//콘솔에서 eof읽어와야함 enter가 아리나 ctrl+d


	bool loop = true;
	FILE* fp;
	char arrayHex[] = {0};
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

	int i = 0;

	while (fgets(str, sizeof(str), fp)) {

		//흠..여기서 흠..하기싫어랑

		createAssembly = readString(str, createAssembly);

		// $41, $42, $43, $44, $45, $46, $47, $48, $49, $4A, $4B, $4C, $4D, $4E, $4F, $50, $0
		// enter 하기 -> 완
		// 마지막 ,랑 $0제거하기 
		// 


		strcpy(dcByte, "dc.b\t");
		strcpy(enter, "\n");
		
		strcat(dcByte, createAssembly);

		/*while (dcByte[i]) {

			i++;
		}
		
		dcByte[i - 1] = "\0";*/

		strcat(dcByte, enter);

		createFile(dcByte, fileName);

	}

	

	// close the file 
	if (fclose(fp) != 0)
	{
		// the closing of the file failed
		printf("Can't close the TEXT file that we were writing to.\n");
		return -3;
	}

	// 3. asm파일로 바꾸기


	return 0;
}



char* readString(char* text, char* createAssembly) {

	char readText[17] = { 0 };
	int ascii = 0;
	char storeArray[100] = { 0 };
	char assembly[100] = { 0 };

	int num1 = 16;
	int num2 = 32;
	int num3 = 144;
	// copy the string into readText
	strcpy(readText, text);

	for (int i = 0; i < sizeof(readText); i++) {

			//\0까지 읽네..?
		
			// read one character and calculate
			ascii = readText[i];


			// Change it to hexadecimal
			sprintf(storeArray, "$%X,", ascii);

			createAssembly = strcat(assembly, storeArray);
		
		ascii = 0;

	}

	return createAssembly;
}

int createFile(char* text, char* textName) {

	char copyText[100];
	strcpy(copyText, text);


	char* name;
	// cut based on "."
	name = strtok(textName, ".");

	// combine the file name and file extension
	strcat(name, ".asm");

	FILE* fp = fopen(name, "a+");

	fputs(copyText, fp);


	if (fclose(fp) != 0)
	{
		// the closing of the file failed
		printf("Can't close the TEXT file that we were writing to.\n");
		return -3;
	}

	return 0;



}
