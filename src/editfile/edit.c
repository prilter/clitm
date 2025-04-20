/*
 * NEED TO EDIT TASK
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/cdefs.h>

#define BUFLEN	 1024
#define	TEMP     ".temp.txt"

__attribute__((cold))
int 
edit(const char *filename, char *new, size_t cl)
{
	FILE *r, *w;
	char *buf;
	size_t i;

	if ( !(r = fopen(filename, "r")) )
		{puts("Usable task list doesn't exist"); return 0;}
	w = fopen(TEMP, "w");

	for (buf = malloc(BUFLEN), i = 1; fgets(buf, BUFLEN, r); i++) {
		if (i == cl) fputs(new, w);
		else				 fputs(buf, w);
	}
	free(buf);
	fclose(r);
	fclose(w);
	
	remove(filename);
	rename(TEMP, filename);

	return 1;
}


