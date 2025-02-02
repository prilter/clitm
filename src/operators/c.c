/*
 * NEED TO REMOVE COMPLETED TASK
*/


#include <stdio.h>
#include <stdlib.h>

#define BUFLEN	 1024

int 
complete(const char *filename, int id)
{
	FILE *file, *temp;
	char buf[BUFLEN];
	int curline;

	/* CHECK FILE */
	if (!fopen(filename, "r"))
		fclose(fopen(filename, "w"));

	/* OPEN FILE DECORATORS */
	file = fopen(filename, "r");
	temp = fopen("temp.txt", "a");

	for (curline = 1; fgets(buf, BUFLEN, file); ++curline)
		if (curline != id)
			fputs(buf, temp);

	fclose(file);
	fclose(temp);

	remove(filename);
	rename("temp.txt", filename);

	return 1;
}


