/*
 ============================================================================
 Name        : ipct.c
 Author      : Vishwadeep Singh
 Version     :
 Copyright   : GNU Licence
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <myreadline/iterator.h>
#include <allcommands.h>

int main(void) {
	puts("!!!Hello World1!!!\n"); /* prints !!!Hello World!!! */
	collatecommands();
	iterator();
	printf("Ends the program\n");
	return EXIT_SUCCESS;
}
