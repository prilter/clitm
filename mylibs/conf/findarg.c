#include <string.h>
#include <stdio.h>
#include <malloc.h>

#define BUFLEN 1024

size_t
findarg(const char *confdir, const char *arg) 
{
	FILE	*f;
	char	*b;
	size_t r;

	f = fopen(confdir, "r");
	b = malloc(BUFLEN);

	for (r = 0; !strstr(b, arg); r++)
		fgets(b, BUFLEN, f);

	fclose(f);
	free(b);

	return r;
}
