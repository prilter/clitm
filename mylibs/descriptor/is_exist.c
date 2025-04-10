/* CHECK IS EXIST FILE */
#include <unistd.h>

int 
is_exist(const char *path) {
	return (access(path, F_OK) != -1);
}
