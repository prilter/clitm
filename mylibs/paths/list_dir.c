/* NEED TO GET SOME LIST DIR */

#include <string.h>

extern char *_get_work_dir(char *);

__attribute__((hot))
char *_get_list_dir(char *buf_dir, const char *list) 
{
	buf_dir = _get_work_dir(buf_dir);
	strcat(buf_dir, list);

	return buf_dir;
}
