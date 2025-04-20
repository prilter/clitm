/* 
THIS FUNCTIONS NEED TO DELETE FROM FILE EVERY LINE WHO EQUAL SECOND ARGUMENT OF FUNCTION
IMPORTANT NOTIFY: toclear ARGUMENT MUST ENDED BY \n
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define BUFLEN 1024
#define TEMP   ".temp.txt"

#define equal(s1, s2) (strcmp(s1, s2) == 0)


__attribute__((cold))
int
clear(const char *dir, char *toclear) 
{
	/* INIT */
	FILE *read, *write;
	char *buf;

	/* USE FILES DESCRIPTORS */
	if (!(read = fopen(dir, "r")))
		return 0;
	write = fopen(TEMP, "w");

	/* MALLOC */
	buf = malloc(BUFLEN);

	/* MAKE NEEDED FILE */
	for (;fgets(buf, BUFLEN, read);)
		if (!equal(buf, toclear))
			fputs(buf, write);

	/* RENAME */
	remove(dir);
	rename(TEMP, dir);

	/* FREE */
	free(buf);
	fclose(read);
	fclose(write);
	
	/* END */
	return 1;
}
