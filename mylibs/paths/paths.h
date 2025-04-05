/* NEED TO USE PATHS FUNCTIONS */

/* EXTERN */
extern char *_gettaskspath(char *);
extern char *_gethomepath(char *);

/* MAKE MORE COMFORTABLE */
#define gettaskspath(taskspath) (taskspath = _gettaskspath(taskspath))
#define gethomepath(b) (b = _gethomepath(b))
