#include <stdio.h>
#include <string.h>
#include "header.h"
#pragma warning(disable: 4996)

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
    int c = 0;
    int i = 0;

    //if (strcmp(argv[0], "encodeInput") == 0) {


   /* argc = 2;
    argv[0] = "encodeInput";
    argv[1] = "-h";*/







    if (argc == oneCmd) {

        //standard input


        while (1)
        {

            c = getchar();
            if (c == 26 || c == -1)
            {
                break;
            }
            input[i] = c;
            i++;

            if (c == 10)
            {
                strcpy(input, "");
                i = 0;
            }
        }




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
            //standard input
            while (1)
            {

                c = getchar();
                if (c == 26 || c == -1)
                {
                    break;
                }
                input[i] = c;
                i++;

                if (c == 10)
                {
                    strcpy(input, "");
                    i = 0;
                }
            }

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
    else if (argc == threeCmd || argc == fourCmd) {

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
    //else if ()
    //{
        // ls -l | encodeInput -odirectory.srec -srec 
        // 
        // pipe all files 
    //}

    else
    {
        printf("ERROR: argc wrong, check the command \n");
    }



    /* }
     else {
         printf("ERROR: What!! arv[0] is worng!! write incodeinput!!\n");
     }
    */

    return 0;
}