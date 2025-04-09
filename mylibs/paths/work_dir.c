/* NEED TO GET HOME PATH(~/.tasks/) */

/* USABLE LIBS */
#include <stdio.h>
#include <unistd.h>

#define TASKSPATH ".tasks"

/* FUNCTION */
char *_get_work_dir(char *b)
{
	sprintf(b, "/home/%s/%s/", getlogin(), TASKSPATH);
	return b;
}
