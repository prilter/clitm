#include <stdio.h>
#include <stdlib.h>

#define BUFLEN	 1024

int
print(const char *filename)
{
	/* INIT */
	FILE  *file;
	char   buf[BUFLEN];
	size_t i;

	/* OPEN FILE */
	if (!fopen(filename, "r"))
		fclose(fopen(filename, "w"));
	file = fopen(filename, "r");

	/* MAIN */
	for (i = 1; fgets(buf, BUFLEN, file);)
		printf("%zd: %s", i++, buf);

	fclose(file);
	return 1;
}
