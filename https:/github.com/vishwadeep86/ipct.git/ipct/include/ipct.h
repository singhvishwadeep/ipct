

typedef struct cmd_ds cmd_ds_t;

cmd_ds_t *cmd_head = NULL;

struct cmd_ds {
	char *name;
	int functional;
	struct cmd_ds *next;
};


