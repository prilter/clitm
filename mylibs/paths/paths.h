extern char *_gettaskspath(char *);
extern char *_gethomepath(char *);

#define gettaskspath(taskspath) (taskspath = _gettaskspath(taskspath))
#define gethomepath(b) (b = _gethomepath(b))
