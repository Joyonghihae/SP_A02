#include <stdio.h>
#include <string.h>
#include "header.h"
#pragma warning(disable: 4996)


// runtime swich란?? 


int main(int argc, char* argv[])
{
    char str[20];
    char input[20];
    int checkArg = 0;
    int number = 0;


    if (argc == 1) {

        //standard input
        //strtok으로 나누기
        //배열 인덱스 개수
        //해당 argument에 넣기
            
        printf("File name: ");


        scanf("%s", str);
        printf("\n");
        strcpy(input, str);
   
        checkArg = checkInputArgument(input);
        number = checkFilename(input);
        if ((number == 1) && (checkArg == 1) ) {

            // encodeInput 만 입력했을때 넘어가는 함수

            printf("Here is argument only 1. Success!!\n");
        }
        else {

            printf("ERROR: Something wrong to oneCmd\n");

            return 0;
        }

    }
    else if (argc == 2) {


        int argnumber = checkTwoCommand(argv[1]);


        if (argnumber == 1)     // input : -h
        {

            help();

            return 0;
        }
        else if (argnumber == 2) 
        {

            checkArg = 0;
            number = 0;

            //standard input
            printf("File name: ");
            scanf("%s", str);
            printf("\n");
            strcpy(input, str);
            checkArg = checkInputArgument(input);
            number = checkFilename(input);


            printf("Here is argument only 2. Success!!\n");
            // encodeInput -omyData.asm 이거만 입력했을때 넘어가는 함수


        }
        else 
        {
            printf("ERROR : Something wrong..!!!\n");

            return -1;
        }

        return 0;
    }
    else if (argc == 3) {

        //encodeInput –srec -imyData.dat 이거 입력했을때 
        checkArg = 0;


        checkArg = checkInputArgument(input);

        return 0;
    }
    else if (argc == 4) {

        //encodeInput -imyData.dat -omyData.srec -srec 이거 입력했을때
        printf("Here is argument only 4. Success!!\n");

        return 0;
    }
    else {
        printf("ERROR: argc wrong, check the command \n");
    }

        // ls -l | encodeInput -odirectory.srec -srec 이건 몇개라고해야될까.. 

   /* }
    else {
        printf("ERROR: What!! arv[0] is worng!! write incodeinput!!\n");
    }
   */

    return 0;
}

