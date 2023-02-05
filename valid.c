#include <stdio.h>
#include <string.h>
#include "header.h"
#pragma warning(disable: 4996)


// ----------------------------------------------------------------main------------------------------------------------------

/*

    1 == -i
    2 == -o
    3 == -h
    4 == user input

*/

int checkFileValidation(char* str) {

    int value = -1;
    char checkcmd[20] = { 0 };
    //char arg[3] = "-i";
    char* cmdI = "-i";
    char* cmdO = "-o";
    char* cmdH = "-h";
    //char* name;
    char point[2] = ".";
    char extension[20] = { 0 };
    
    char* ptr = strstr(str, point);


    if ((ptr == NULL)) {

        printf("ERROR: Not specified\n");

        return value;
    } else {

        if (strncmp(str, cmdI, 2) == 0) {

            /*name = strtok(str, point);
            while (name != NULL) {

                strcpy(extension, name);
                name = strtok(NULL, " ");

                if (strcmp(extension, "dat") == 0) {

                    printf("Success!! dat \n");

                    value = 1;

                    return value;
                }

            }*/
            value = 1;

            return value;
        }
        else if (strncmp(str, cmdO, 2) == 0) {

           /* name = strtok(str, point);
            while (name != NULL) {

                strcpy(extension, name);
                name = strtok(NULL, " ");
                if (strcmp(extension, "asm") == 0) {

                    printf("Success!! asm \n");

                    value = 2;

                    return value;

                }


                return value;
            }*/

            value = 2;

            return value;

        }
        else if (strncmp(str, cmdH, 2) == 0) {

            printf("Success!! -h \n");

            value = 3;

            return value;
        }
        else {

            //stdin입력시 이쪽으로 빠짐  
            value = 4;
            
            return value;

        }
      
    }


    return value;
}


// ----------------------------------------------------------------main------------------------------------------------------


// runtime switch제거 -i든 -o든 여기서 사용 
void removeSwitch(char* str, char ch, char ch1) {

    for (; *str != '\0'; str++) {

        if (*str == ch1) {

            strcpy(str, str + 1);
            str--;


        }

        if (*str == ch) {
            strcpy(str, str + 1);
            str--;

            break;
        }

    }
}

int checkSrec(char* str)
{
    if (strcmp(str, "-srec") == 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}