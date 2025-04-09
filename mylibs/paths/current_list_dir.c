/* NEED TO GET .USABLE FILE DIR */

#include <malloc.h>
#include "../../config.h"

extern char *_get_work_dir(char *);
extern char *_get_current_list_name(char *, unsigned int);

#define DIRLEN 1024
#ifndef NAMELEN
	#define NAMELEN 1024
#endif

char *_get_current_list_dir(char *dir) 
{
	char *taskspath, *usable;

	taskspath = malloc(DIRLEN);
	usable    = malloc(NAMELEN);

	taskspath = _get_work_dir(taskspath);
	usable    = _get_current_list_name(usable, NAMELEN);

	sprintf(dir, "%s%s", taskspath, usable);
	return dir;
}
