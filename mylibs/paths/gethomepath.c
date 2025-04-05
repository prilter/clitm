/* NEED TO GET HOME PATH */

/* USABLE LIBS */
#include <stdio.h>
#include <unistd.h>

/* FUNCTION */
char *_gethomepath(char *b)
{
	sprintf(b, "/home/%s", getlogin());
	return b;
}
