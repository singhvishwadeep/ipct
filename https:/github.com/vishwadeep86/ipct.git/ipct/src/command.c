/*
 * command.c
 *
 *  Created on: 26-Feb-2016
 *      Author: vishwadeep
 */
#include <stdio.h>
#include <string.h>
#include <myreadline/iterator.h>

int identifycommand (const char *cmd) {
	char *each;
	each = strtok (cmd," \t");
	trimwhitespace(each);
	printf ("%s\n",each);
	if (searchcommands(each)) {
		printf("Unidentified command found %s\n",cmd);
		return 1;
	}

	printf("Executing command-> %s\n",cmd);
	return 0;
}

int cmdgo (const char* cmd) {
	int ret = identifycommand(cmd);
	return ret;
}

