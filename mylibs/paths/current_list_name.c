/* NEED TO GET USABLE TASK LIST */

/* USABLE LIBS */
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/* CONFIG */
#include "../../config.h"

/* MACROSES */
#ifndef NAMELEN
	#define NAMELEN  1024
#endif
#define TASKSDIRLEN  1024

extern char * _get_work_dir(char *);
char *_get_current_list_name(char *tasklist, int size) 
{
	FILE *read;
	char *usabledir;

	usabledir = malloc(TASKSDIRLEN);

	usabledir = _get_work_dir(usabledir);
	strcat(usabledir, ".usable");
	
	read = fopen(usabledir, "r");
	fgets(tasklist, size, read);

	fclose(read);
	free(usabledir);
	return tasklist;
}
