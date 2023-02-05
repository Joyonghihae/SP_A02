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
    char input[20];
   // char str2[20];
    int checkArg = 0;
    int number = 0;
    int srec = 0;
    int output = 0;

    //if (strcmp(argv[0], "encodeInput") == 0) {


   /* argc = 2;
    argv[0] = "encodeInput";
    argv[1] = "-h";*/



    if (argc == oneCmd) {

        //standard input
            
        printf("File name: ");


        scanf("%s", str);
        printf("\n");
        strcpy(input, str);
 
        checkArg = checkFileValidation(input);
        //number = checkFilename(str2);
        if (checkArg == 4) {

            // encodeInput 만 입력했을때 넘어가는 함수
            //standard input into Assembly 
            inputAssembly(str);


            printf("Here is argument only 1. Success!!\n");
        }
        else {

            printf("ERROR: Something wrong to oneCmd\n");

            return 0;
        }

    }
    else if (argc == twoCmd) {


        int argnumber = checkFileValidation(argv[1]);


        if (argnumber == 3) {

            printf("Here is argument -h. Success!!\n");

            help();

            //encodeInput -h 이거 입력했을때 넘어가는 함수 

            return 0;
        }
        else if (argnumber == 2) {

            checkArg = 0;
            number = 0;
            //standard input
            printf("File name: ");
            scanf("%s", str);
            printf("\n");
            strcpy(input, str);
            //strcpy(str2, str);
            checkArg = checkFileValidation(input);
            //number = checkFilename(str2);

            // checkArg에서 넘어오면 3으로 넘어올듯

            printf("Here is argument only 2. Success!!\n");
            // encodeInput -omyData.asm 이거만 입력했을때 넘어가는 함수


        }
        else {
            printf("ERROR : Something wrong..!!!\n");

            return -1;
        }

        return 0;
    }
    else if (argc == threeCmd) {

        //encodeInput –srec -imyData.dat 이거 입력했을때 
       

        for (int i = 0; i < argc - 1; i++)
        {
          
            strcpy(input, argv[i+1]);
            if (checkSrec(input) == 1)
            {
                srec = 1;
                continue;
            }
            else if (checkFileValidation(input) == 1)
            {
                checkArg = 1;
                continue;
            }
            else if (checkFileValidation(input) == 2)
            {
                output = 1;
                continue;
            }
            else
            {
                printf("Error: Wrong Input");
            }
           
        }

        if ((srec == 1) && (checkArg == 1))
        {
         
            //s-record function
        }
        else if ((srec != 1) && (checkArg == 1) && (output == 1))
        {
            //assembly function
        }



        return 0;
    }
    else if (argc == fourCmd) {

        //encodeInput -imyData.dat -omyData.srec -srec 이거 입력했을때

        for (int i = 0; i < argc - 1; i++)
        {

            strcpy(input, argv[i + 1]);
            if (checkSrec(input) == 1)
            {
                srec = 1;
                continue;
            }
            else if (checkFileValidation(input) == 1)
            {
                checkArg = 1;
                continue;
            }
            else if (checkFileValidation(input) == 2)
            {
                output = 1;
                continue;
            }
            else
            {
                printf("Error: Wrong Input");
            }

        }

        if ((srec == 1) && (checkArg == 1) && (output == 1))
        {
            printf("s-record");
        }
        else if ((srec != 1) && (checkArg == 1) && (output == 1))
        {
            printf("assembly");
        }


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

