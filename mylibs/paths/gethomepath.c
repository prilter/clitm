#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>

char *_gethomepath(char *b)
{
	strcat(b, "/home/");
	strcat(b, getlogin());
	
	return b;
}
