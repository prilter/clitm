#include <string.h>
#include <stdio.h>

#define RLEN 1024

char *
_getarg(const char *confdir, char *b, size_t line) 
{
	FILE *f;

	f = fopen(confdir, "r");
	for (;line--;)
		fgets(b, RLEN, f);
	fclose(f);

	if (strstr(b, ":")) {
		b = strstr(b, ":");
		for (b++ ;*b == ' ' || *b == '\t'; b++)
			*(b+strlen(b)-1) = '\0';
	}
	return b;
}
