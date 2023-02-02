#include <stdio.h>
#include <string.h>
#include "header.h"
#pragma warning(disable: 4996)


// runtime swich란?? 


int main(int argc, char* argv[])
{
	
    int oneCmd = 1;
    int twoCmd = 2;
    int threeCmd = 3;
    int fourCmd = 4;
    char str[20];

    if (strcmp(argv[0], "encodeInput") == 0) {

        if (argc == oneCmd) {

            //standard input
            
            printf("File name: ");
            fgets(str, 20, stdin);
            printf("\n");
            int number = checkFilename(str);
            if (number == 1) {

                // encodeInput 만 입력했을때 넘어가는 함수

            }
            else {
                printf("ERROR: Something wrong to oneCmd\n");
            }

        }
        else if (argc == twoCmd) {

            int argnumber = checkTwoCommand(argv[1]);


            if (argnumber == 1) {

                //encodeInput -h 이거 입력했을때 넘어가는 함수 

            }
            else if (argnumber == 2) {

                //standard input
                printf("File name: ");
                fgets(str, 20, stdin);
                printf("\n");
                checkFilename(str);
                
                // encodeInput -omyData.asm 이거만 입력했을때 넘어가는 함수


            }
            else {
                printf("ERROR : Something wrong..!!!\n");

                return -1;
            }

        }
        else if (argc == threeCmd) {

            //encodeInput –srec -imyData.dat 이거 입력했을때 


        }
        else if (argc == fourCmd) {

            //encodeInput -imyData.dat -omyData.srec -srec 이거 입력했을때

        }

        // ls -l | encodeInput -odirectory.srec -srec 이건 몇개라고해야될까.. 


    }
    else {
        printf("ERROR: What!! arv[0] is worng!! write incodeinput!!\n");
    }
   

    return 0;
}


int checkFilename(char* str) {

    // check: 파일이 아니면? 혹은 -ifilename.dat이 아니면?? 체크해야됨
    // 1. .이 없으면 -> strstr
    // 2. -i가 없으면 -> strstr
    //아 하기싫어.. 유진님 뭐하시나.. 이거좀해줘요

    int value = 0;
    char* name;
    char* cmd;
    char extension[2] = { 0 };
    char checkcmd[2] = { 0 };
    char point[] = ".";
    char arg[] = "-i";

    char* ptr = strstr(str, point);
    char* ptr1 = strstr(str, arg);

    if ((ptr == NULL) || ptr1 == NULL) {

        printf("ERROR: Not specified\n");

        value = -1;
    }


    // cut based on ".". "-i"
    name = strtok(str, ".");
    cmd = strtok(str, "-i");
    int i = 0;


    while (name != NULL) {

        strcpy(extension, name);
        name = strtok(NULL, " ");

        i++;
    }
    
    i = 0;
    while (cmd != NULL) {
        strcpy(checkcmd, cmd);

        cmd = strtok(NULL, " ");

        i++;
    }

    i = 0;

    // "dat"을 체크해야되나?
    if (strncmp(extension, "dat", 2) == 0) {


        value = 1;
    }
    else if (strncmp(checkcmd, "-i", 1) == 0) {

        value = 1;
    }


    return value;
}

int checkTwoCommand(char* argv) {

    int value = 0;
    char* name;
    char extension[3] = { 0 };

    char point[] = ".";
    char arg[] = "-i";

    char* ptr = strstr(argv, point);
    char* ptr1 = strstr(argv, arg);

    if ((ptr == NULL) || ptr1 == NULL) {
        printf("ERROR: not specified\n");

        value = -2;
    }


    // cut based on "."
    name = strtok(argv, ".");
    int i = 0;


    while (name != NULL) {
        
        strcpy(extension, name);
        name = strtok(NULL, " ");

        i++;
    }

    if (strcmp(argv, "-h") == 0) {


        value = 1;
    }
    else if (strncmp(extension, "asm", 2) == 0) {

        value = 2;
    }
    else {

        printf("ERROR: Please write file name or help\n");

        value = -1;
    }

    return value;
}
