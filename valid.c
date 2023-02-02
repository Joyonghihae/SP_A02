#include <stdio.h>
#include <string.h>
#include "header.h"
#pragma warning(disable: 4996)


// ----------------------------------------------------------------main------------------------------------------------------
int checkFilename(char* str) {

    // check: 파일이 아니면? 혹은 -ifilename.dat이 아니면?? 체크해야됨
    // 1. .이 없으면 -> strstr
    // 2. -i가 없으면 -> strstr
    //아 하기싫어.. 유진님 뭐하시나.. 이거좀해줘요

    int value = 0;
    char* name;
    char extension[20] = { 0 };
    char checkcmd[20] = { 0 };
    char point[2] = ".";

    char* ptr = strstr(str, point);

    if (ptr == NULL) {

        printf("ERROR: Not specified\n");

        value = -1;

        return value;
    }
    else {

        // cut based on ".". "-i"
        name = strtok(str, point);

        while (name != NULL) {

            strcpy(extension, name);
            name = strtok(NULL, " ");
            
            // *********** error *****************
            // 만약 -iddd.dat이 아니라 -idafd.asm이면?
            // 반대로 -oaa.asm이 아니라 -oddd.dat이면?
            // 아 귀찮네 

            if (strcmp(extension, "dat") == 0) {

                printf("Success!! dat \n");

                value = 1;

                return value;
            }
            else if (strcmp(extension, "asm") == 0) {

                printf("Success!! asm \n");

                value = 1;

                return value;

            }
        }
    }


    if (value == 0) {

        value = -1;

        return value;
    }


    return value;
}

int checkInputArgument(char* str) {

    int value = 0;
    char* cmd;
    char checkcmd[20] = { 0 };
    char arg[3] = "-i";

    char* ptr1 = strstr(str, arg);

    if (ptr1 == NULL) {

        printf("ERROR: Not specified\n");

        value = -1;

        return value;
    }
    else {
        cmd = strtok(str, "i");

        while (cmd != NULL) {
            strcpy(checkcmd, cmd);

            cmd = strtok(NULL, " ");

            if (strcmp(checkcmd, "-") == 0) {

                printf("Success!! -i \n");
                value = 1;

                return value;
            }

        }

    }

    if (value == 0) {

        value = -1;

        return value;
    }

    return value;
}



int checkTwoCommand(char* argv) {

    int value = 0;
    char extension[3] = { 0 };

    char arg[] = "-h";
    char str1[20];
    char str2[20];



    // -h
    // -o, asm 확인


    if (strcmp(argv, arg) == 0) {

        printf("Success!! -h \n");

        value = 1;

        return value;
    }
    else {

        strcpy(str1, argv);
        strcpy(str2, argv);

        int dd = checkOutputArgument(str1);
        int aa = checkFilename(str2);

        if ((dd == 1) && (aa == 1)) {

            printf("Success!! Two Command Argument, -omyData.asm \n ");

            value = 2;

            return value;
        }
        else {

            printf("ERROR: Something wrong to twoCmd\n");

            value = -1;

            return value;
        }
    }

    if (value == 0) {

        value = -1;

        return value;
    }


    return value;
}

int checkOutputArgument(char* str) {
    int value = 0;
    char* cmd;
    char checkcmd[20] = { 0 };
    char arg[3] = "-o";

    char* ptr1 = strstr(str, arg);

    if (ptr1 == NULL) {

        printf("ERROR: Not specified\n");

        value = -1;

        return value;
    }
    else {
        cmd = strtok(str, "o");

        while (cmd != NULL) {
            strcpy(checkcmd, cmd);

            cmd = strtok(NULL, " ");

            if (strcmp(checkcmd, "-") == 0) {

                printf("Success!! -o \n");
                value = 1;

                return value;
            }

        }

    }

    if (value == 0) {

        value = -1;

        return value;
    }

    return value;
}


// ----------------------------------------------------------------main------------------------------------------------------