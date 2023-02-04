#include <stdio.h>
#include <string.h>
#include "header.h"
#pragma warning(disable: 4996)


// ----------------------------------------------------------------main------------------------------------------------------
int checkFilename(char* str) {

    // check: 파일이 아니면? 혹은 -ifilename.dat이 아니면?? 체크해야됨
    // 1. .이 없으면 -> strstr
    // 2. -i가 없으면 -> strstr


    int value = 0;
    char* name = NULL;
    char extension[20] = { 0 };
    char checkcmd[20] = { 0 };
    char* fileName = NULL;


    name = strstr(str, ".");

    if (name == NULL)
    {

        printf("ERROR: Not specified\n");

        value = -1;

        return value;
    }
    else 
    {

        if (strstr(name, "-i") != NULL)
        {
            name = strtok_s(name, "i", &fileName);
        }
        else if (strstr(name, "-o" != NULL))
        {
        }

        
     
            // output은 확장자가달라도 상관없기에 수정해야함
          // 수정해야함  str = strtok_s(NULL, " ", &fileName);
            
            // *********** error *****************
            // 만약 -iddd.dat이 아니라 -idafd.asm이면?
            // 반대로 -oaa.asm이 아니라 -oddd.dat이면?
  
            //if (strcmp(extension, "dat") == 0) {

            //    printf("Success!! dat \n");

            //    value = 1;

            //    return value;
            //}
            //else if (strcmp(extension, "asm") == 0) {

            //    printf("Success!! asm \n");

            //    value = 1;

            //    return value;

            //}
        }
    }


    //

int checkInputArgument(char* str) {

    int value = -1;
    char* cmd;
    char checkcmd[20] = { 0 };


    char* ptr1 = strstr(str, "-i");

    if (ptr1 == NULL) {

        printf("ERROR: Not specified\n");

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


    return value;
}



int checkTwoCommand(char* argv) {

    int value = -1;
    char extension[3] = { 0 };


    char input[20];



    if (strcmp(argv, "-h") == 0) {


        value = 1;

        return value;
    }
    else {

        strcpy(input, argv);
  

        int output = checkOutputArgument(input);
        int fileName = checkFilename(input);

        if ((output == 1) && (fileName == 1)) {

            printf("Success!! Two Command Argument, -omyData.asm \n ");

            value = 2;

            return value;
        }
        else {

            printf("ERROR: Something wrong to twoCmd\n");

            return value;
        }
    }



    return value;
}

int checkOutputArgument(char* str) {
    int value = -1;
    char* cmd;
    char checkcmd[20] = { 0 };
    char arg[3] = "-o";

    char* ptr1 = strstr(str, arg);

    if (ptr1 == NULL) {

        printf("ERROR: Not specified\n");

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
            }

        }

    }


    return value;
}


// ----------------------------------------------------------------main------------------------------------------------------