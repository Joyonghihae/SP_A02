#include <stdio.h>
#include <string.h>
#include "header.h"
#pragma warning(disable: 4996)
// help

void help() {

	printf("\nFor more information on a specific command\n\n"
		"------------------------------------------------------------------------------\n"
		"encodeInput\t-i[filename].dat\t\t\t Convert dat to srec as an S-Record file\n"
		"\t\t-o[filename].asm\t\t\t Convert standard input into asm as an assembly file\n"
		"\t\t-i[filename].dat -o[filename].srec -srec Convert dat to srec as an S-Record file\n"
		"\t\t-srec -i[filename].dat\t\t\t Convert data from dat into .dat.srec as an S-Record file\n"
		"\t\tls -l | encodeInput -odirectory.srec -srec => I don't know\n" 
		"\t\t-h\t\t\t\t\t Help information\n" 
		"\t\tdefault\t\t\t\t\t Convert standard input into Assembly formatted standard output\n"
		"------------------------------------------------------------------------------\n");

}