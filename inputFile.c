#include <stdio.h>
#include <string.h>
#include "header.h"
#pragma warning(disable: 4996)

// 입력하는곳은 -i를 없이 입력해야됨 -> 완
// encodeInput -omyData.asm
// stdin으로 사용자 파일 받아옴 -> 완
// 2가지 기능 1. s-record랑 하나는 asembbly 파일 만들기
// -srec가 붙인게 s-record
// 아닌건 assembly

// 확장자를 구분할 필요는 없을듯. 제길-> 완


void inputAssembly(char* argv) {


	// -iddd.dat 이렇게 입력

	
	// 1. -i제거하기 
	removeSwitch(argv, 'i', '-');
	

	//1.  dc.b는 한줄씩 계속 반복해서 붙이기
	//2. 이거.. 16진수인가 뭐야이거 음 $해서..음음음 아놔 
	// 2자리 16진수로 표시 
	// 각라인은 최대 16캐릭터만 표시가능 
	bool loop = true;
	FILE* fp;

	char fileName[20];
	strcpy(fileName, argv);

	char* ch;

	fp = fopen(fileName, "r");

	if (fp == NULL) {

		printf("There is no file");

		return -1;
	}

	while ((ch = fgetc(fp)) != EOF) {

		//흠..여기서 흠..하기싫어랑


	}



	// close the file 
	if (fclose(fp) != 0)
	{
		// the closing of the file failed
		printf("Can't close the TEXT file that we were writing to.\n");
		return -3;
	}

	// 3. asm파일로 바꾸기



}

