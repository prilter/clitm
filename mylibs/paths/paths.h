/* NEED TO USE PATHS FUNCTIONS */

/* EXTERN */
extern char *_get_work_dir(char *);
extern char *_get_current_list_name(char *, int);
extern char *_get_current_list_dir(char *);
extern char *_get_list_dir(char *, const char *);

/* MAKE MORE COMFORTABLE */
#define get_work_dir(workdir)  	    (workdir = _get_work_dir(workdir))
#define get_current_list_name(b,sz)	(b = _get_current_list_name(b, sz))
#define get_current_list_dir(arg)   (arg = _get_current_list_dir(arg))
#define get_list_dir(dir, list)     (dir = _get_list_dir(dir, list))

/* 
 * GET LIST DIR:  + 
 * GET TASK PATH -> + 
 * GET USABLE DIR -> + 
 * GET USABLE LIST -> CURRENT LIST NAME
*/
