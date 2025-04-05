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
#define HOMELEN  1024

extern char * _gethomepath(char *);
char *_gettaskspath(char *taskspath) 
{
	char *buf, *usable_file, *homedir;
	
	/* MALLOC */
	buf         = malloc(NAMELEN);
	usable_file = malloc(HOMELEN);
	homedir     = malloc(HOMELEN);

	/* GET USABLE & HOME DIR */
	usable_file = _gethomepath(usable_file);
	homedir     = _gethomepath(homedir);
	strcat(usable_file, "/.tasks/.usable");

	/* GET A TASKS LIST PATH */
	fgets(buf, NAMELEN, fopen(usable_file, "r"));
	sprintf(taskspath, "%s/.tasks/%s", homedir, buf);

	/* END */
	free(buf);
	free(usable_file);
	free(homedir);
	return taskspath;
}
