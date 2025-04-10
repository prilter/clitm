#include <stdio.h>
#include <malloc.h>

#define BUFLEN 1024

size_t filelen(const char *path) 
{
	FILE  *r;
	char  *b;
	size_t res;
	
	b = malloc(BUFLEN);
	r = fopen(path, "r");

	for (res = 0; fgets(b, BUFLEN, r);)
		res++;

	fclose(r);
	free(b);
	return res;
}
