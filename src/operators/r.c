#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int edit(const char *fm, const char *new, size_t line);

#define BUFLEN	 1024
#define TASKLEN  100

int 
replace(const char *filename, size_t l1, size_t l2) 
{
	FILE *r;
	char *b1, *b2;
	size_t i;

	if (l1 == l2)
		return 1;

	if (!fopen(filename, "r"))
		{printf("Have no \"%s\"", filename); return 0;}

	b1 = malloc(TASKLEN);
 	b2 = malloc(TASKLEN);

	/* GETTING b1 AND b2 */
	r = fopen(filename, "r");
	for (i = 1; i <= l1 && fgets(b1, BUFLEN, r); i++);
	fclose(r);

	r = fopen(filename, "r");
	for (i = 1; i <= l2 && fgets(b2, BUFLEN, r); i++);
	fclose(r);

	/* MOVE */
	edit(filename, b2, l1);
	edit(filename, b1, l2);

	free(b1);
	free(b2);

	return 1;
}
