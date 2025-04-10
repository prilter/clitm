/* NEED TO PRINT FILES FROM DIRECTORY */

/* LIBS */
#include <dirent.h>
#include <stdio.h>

#define dirent struct dirent

/* FUNCTIONS */
int ls(const char *path) {
	/* INIT */
	DIR    *dir;
	dirent *ent;
	int     res;

	/* OPEN THE DIR */
	dir = opendir(path);
	if ((res = (dir != NULL))) {
		for (;(ent = readdir(dir));)
			if (*(ent->d_name) != '.')
				{puts(ent->d_name);}
	}

	closedir(dir);
	return res;
}
