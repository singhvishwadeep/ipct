/*
 * iterator.c
 *
 *  Created on: 26-Feb-2016
 *      Author: vishwadeep
 */


#include <stdio.h>
#include <string.h>
#include <command.h>

const char *prompt = "ipcterminal@ipc >";

char *trimwhitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace(*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace(*end)) end--;

  // Write new null terminator
  *(end+1) = 0;

  return str;
}

int iterator () {
	char *buffer = NULL;
	int read;
	unsigned int len;
	while (1) {
		printf("%s", prompt);
		read = getline(&buffer, &len, stdin);
		trimwhitespace(buffer);
		if (strcmp(buffer,"\0") == 0) {
			break;
		}
		if (strcmp("quit",buffer) == 0 || strcmp("q",buffer) == 0 || strcmp("bye",buffer) == 0 || strcmp("exit",buffer) == 0) {
			break;
		} else {
			fprintf(stdout,"$?=%d\n",cmdgo(buffer));
		}
	}
	return 1;
}
