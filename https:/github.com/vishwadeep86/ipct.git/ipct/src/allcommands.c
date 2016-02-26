/*
 * allcommands.c
 *
 *  Created on: 26-Feb-2016
 *      Author: vishwadeep
 */

#include <stdio.h>
#include <stdlib.h>
#include <ipct.h>
#include <string.h>

const char * commands[] = {"info","hello","ls","bye","q","quit","exit","show",\
							"help","fork","socket","shared_mem","pipe","semaphore",\
							"thread","fifo","about"};


void consideredcommands () {
	cmd_ds_t *cmd = cmd_head;
	int i = 0;
	while (cmd) {
		i++;
		printf("%d) considering %s\n",i,cmd->name);
		cmd = cmd->next;
	}
}

void collatecommands () {
	int i;
	cmd_ds_t *cmd = NULL;
	cmd_ds_t *temp = NULL;
	for (i =0; i < sizeof(commands) / sizeof(commands[0]); i++) {
		cmd = (cmd_ds_t *) malloc (sizeof(cmd_ds_t));
		if (!cmd_head) {
			cmd_head = cmd;
		}
		if (temp) {
			temp->next = cmd;
		}
		cmd->name = (char *) malloc (sizeof(char) * strlen(commands[i]));
		strcpy(cmd->name,commands[i]);
		cmd->functional = 1;
		cmd->next = NULL;
		temp = cmd;
	}
	consideredcommands();
	return;
}


int searchcommands (const char*name) {
	cmd_ds_t *cmd = cmd_head;
	while (cmd) {
		if (strcmp(name,cmd->name) == 0) {
			return 0;
		}
		cmd = cmd->next;
	}
	return 1;
}
