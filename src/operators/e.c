#include <stdio.h>
#include <stdlib.h>

#define BUFLEN	 1024

int 
edit(const char *filename, const char *new, size_t cl)
{
	FILE *r, *w;
	char *buf;
	size_t i;

	if ( !(r = fopen(filename, "r")) )
		{printf("Have no \"%s\"", filename); return 0;}
	w = fopen(".temp.txt", "w");

	for (buf = malloc(BUFLEN), i = 1; fgets(buf, BUFLEN, r); i++) {
		if (i == cl) fputs(new, w);
		else				 fputs(buf, w);
	}
	free(buf);
	fclose(r);
	fclose(w);
	
	remove(filename);
	rename(".temp.txt", filename);

	return 1;
}


