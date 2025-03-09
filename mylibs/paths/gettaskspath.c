#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define TASKSLEN 1024
#define HOMELEN  1024

extern char * _gethomepath(char *);
char *_gettaskspath(char *taskspath) 
{
	char *buf, *usable_file, *homedir;
	
	/* MALLOC */
	buf         = malloc(TASKSLEN);
	usable_file = malloc(HOMELEN);
	homedir     = malloc(HOMELEN);

	/* GET USABLE & HOME DIR */
	usable_file = _gethomepath(usable_file);
	homedir     = _gethomepath(homedir);
	strcat(usable_file, "/.tasks/usable");

	/* GET A TASKS LIST PATH */
	fgets(buf, TASKSLEN, fopen(usable_file, "r"));
	sprintf(taskspath, "%s/.tasks/%s", homedir, buf);

	/* END */
	free(buf);
	free(usable_file);
	free(homedir);
	return taskspath;
}
