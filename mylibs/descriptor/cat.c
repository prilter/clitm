/* USE SOMETHING LIKE CAT SHELL COMMAND */
#include <stdio.h>
#include <malloc.h>

#define BUFLEN 1024

int 
cat(const char *fn) 
{
	FILE  *r;
	char  *b;
	size_t i;

	if ((r = fopen(fn, "r"))) {
		b = malloc(BUFLEN);
		for (i = 1; fgets(b, BUFLEN, r);)
			printf("%zd: %s", i++, b);
		
		fclose(r); 
		free(b);
		return 1;
	}

	return 0;
}
