#include <stdio.h>

#define BUFLEN 1024

int 
help(void) 
{
	puts("-p: print all tasks");					/* pmenu */
	puts("-n: make new task");						/* nmenu */
	puts("-c: commit task as commit");		/* cmenu */
	puts("-r: replace task 1 and task2");	/* rmenu */
	puts("-e: edit task info by id");			/* emenu */
	puts("-h: help menu");								/* hmenu */

	return 1;
}
