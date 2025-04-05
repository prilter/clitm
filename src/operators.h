/* EVERY FLAG OPERATIONS */

/* LIBS */
#include <stdio.h>
#include <string.h>

/* CONFIG */
#include "../config.h"

/* EXTERN */
extern int edit(const char *, const char *, size_t); /* FROM e.c */
extern int replace(const char *, size_t, size_t);    /* FROM r.c */
extern int print(const char *);                      /* FROM p.c */
extern int complete(const char *, int);              /* FROM c.c */

/* MACROSES */
#define DIRLEN   100
#define BUFLEN   1024
#define RESLEN   1024
#define COMLEN	 1024
#define NONPATH  "Nothing\t   "

#ifndef TASKSLEN
	#define TASKSLEN 100
#endif

#ifndef TASKLEN
	#define TASKLEN  100
#endif

#ifndef NAMELEN
	#define NAMELEN  100
#endif

#ifndef NOTASKS	
	#define NOTASKS	 "No tasks"
#endif

#ifndef EDITOR
	#define EDITOR "nano"
#endif


#define make(fn) fclose(fopen(fn, "w"))

/* DEFAULT FLAGS */
/* PRINT ALL TASKS FROM CURRENT TASK LIST */
#define p(fn)	{															   \
	FILE *r;                                     \
	char *buf;      													   \
																						   \
	buf = malloc(BUFLEN);                        \
	if ((r = fopen(fn, "r"))) {                  \
		if (!(fgets(buf, BUFLEN, r)))              \
			puts(NOTASKS);													 \
		else																			 \
			{puts("Tasks:");print(fn);}							 \
		fclose(r);                                 \
	} else puts("Choose the usable task list");  \
	free(buf);                                   \
}


/* PRINT ALL TASKS FROM CHOOSED TASK LIST */
#define s(fn) {                               \
	char *ldir, *buf;                           \
                                              \
	ldir = malloc(DIRLEN);                      \
	buf  = malloc(BUFLEN);                      \
				                                      \
	gethomepath(ldir);                          \
	strcat(ldir, "/.tasks/");                   \
	strcat(ldir, fn);                           \
																						  \
	if ((fopen(ldir, "r"))) {                   \
		if (!(fgets(buf,BUFLEN,fopen(ldir,"r"))))	\
			puts(NOTASKS);													\
		else																			\
			{puts("Tasks:");print(ldir);}						\
	} else puts("Invalid task list name");      \
                                              \
	free(ldir); free(buf);                      \
}


/* EDIT 1 LINE IN CURRENT TASK LIST */
#define e(l, filename) {												  \
	char *b;																			  \
	if (fopen(filename, "r")) {                     \
		fgets((b = malloc(BUFLEN)), BUFLEN, stdin);  	\
		edit(filename, b, l);													\
		free(b);																			\
	} else puts("Choose the usable task list");     \
}


/* SEE ALL TASK LISTS */
#include <dirent.h> /* TO WORK WITH DIRECTORIES INFORMATION */
#define l() {                                   \
	/* VARIABLES */                               \
	DIR  *dir;                                    \
	char *usabledir;                              \
	struct dirent *ent;                           \
                                                \
	/* GET DIR */                                 \
	usabledir = malloc(DIRLEN);                   \
	gethomepath(usabledir);                       \
	strcat(usabledir, "/.tasks");                 \
                                                \
	/* OPEN THE DIR */                            \
	if ((dir = opendir(usabledir)) != NULL) {     \
		for (;(ent = readdir(dir));)                                 \
			if (strcmp(ent->d_name, ".usable") && *(ent->d_name) != '.')\
				{puts(ent->d_name);}                    \
	} else                                        \
		{puts("We lost your tasks lists. Sorry");}  \
                                                \
	closedir(dir);                                \
	free(usabledir);                              \
}


/* MAKE A TASK LIST */
#define b(list) {               \
	char *listdir;                \
	if (*list != '.') {           \
		listdir = malloc(DIRLEN);   \
		gethomepath(listdir);       \
		strcat(listdir, "/.tasks/");\
		strcat(listdir, list);      \
		                      			\
		make(listdir);              \
		free(listdir);              \
	} else                        \
		puts("Dot is illegal");     \
}


/* MOVE TO OTHER TASK LIST */
#include <unistd.h> /* TO CHECK EXTISTING OF FILE IN DIRECTORY */
#define m(list) {\
	FILE *w;                              \
	char *listdir, *usabledir;            \
                                        \
	listdir   = malloc(DIRLEN);           \
	usabledir = malloc(DIRLEN);           \
                                        \
	gethomepath(listdir);                 \
	strcat(listdir, "/.tasks/");          \
	strcat(listdir, list);                \
                                        \
	gethomepath(usabledir);               \
	strcat(usabledir, "/.tasks/.usable"); \
                                        \
	if (access(listdir, F_OK) != -1) {    \
		w = fopen(usabledir, "w");          \
		fputs(list, w);                     \
		fclose(w);                          \
	} else                                \
		printf("%s doesn't exist. Use -M\n", list);\
                                        \
	free(listdir);                        \
	free(usabledir);                      \
}


/* KILL TASK LIST */
#define k(list) {                                    \
	FILE *read;                                        \
	char *listdir, *usinglist, *usabledir;             \
                                                     \
	listdir   = malloc(DIRLEN);                        \
	usabledir = malloc(DIRLEN);                        \
	usinglist = malloc(BUFLEN);                        \
                                                     \
	gethomepath(usabledir);                            \
	strcat(usabledir, "/.tasks/.usable");              \
	read = fopen(usabledir, "r");                      \
	fgets(usinglist, BUFLEN, read);                    \
	                                                   \
	gethomepath(listdir);                              \
	strcat(listdir, "/.tasks/");                       \
	strcat(listdir, list);                             \
                                                     \
	if (strcmp(usinglist, list))/* FILE CAN NOT EXIST*/\
		remove(listdir);                                 \
	else if (strcmp(usinglist, NONPATH) == 0)          \
		puts("\"Nothing\" is not a task list");          \
	else                                               \
		puts("You can't. Change the tasks list");        \
                                                     \
	fclose(read);                                      \
	free(listdir);                                     \
	free(usinglist);                                   \
	free(usabledir);                                   \
}


/* ALIAS TASK LIST */
#define a(tdir, oldn, newn) { \
	char *oldpath, *newpath;    \
                              \
	oldpath = malloc(DIRLEN);   \
	newpath = malloc(DIRLEN);   \
                              \
	gethomepath(oldpath);       \
	strcat(oldpath, "/.tasks/");\
	strcat(oldpath, oldn);      \
                              \
	gethomepath(newpath);       \
	strcat(newpath, "/.tasks/");\
	strcat(newpath, newn);      \
                              \
	if (strcmp(tdir, oldpath))  \
		rename(oldpath, newpath); \
	else                        \
		puts("Change task list"); \
	free(oldpath);              \
	free(newpath);              \
}


/* CHECK USABLE TASK LIST */
#define u()	{                             \
	FILE *read;                             \
	char *usable_path, *res;                \
                                          \
	usable_path = malloc(DIRLEN);           \
	gethomepath(usable_path);               \
	strcat(usable_path, "/.tasks/.usable"); \
	read        = fopen(usable_path, "r");  \
                                          \
	res = malloc(RESLEN);                   \
	fgets(res, RESLEN, read);               \
	puts(res);                              \
                                          \
	fclose(read);                           \
	free(usable_path);                      \
	free(res);                              \
}


/* QUIT FROM TASK LIST */
#define q() {                           \
	FILE *edit;                           \
	char *usablefile;                     \
                                        \
	usablefile = malloc(DIRLEN);          \
	gethomepath(usablefile);              \
	strcat(usablefile, "/.tasks/.usable");\
	                                      \
	edit = fopen(usablefile, "w");        \
	fputs(NONPATH, edit);                 \
                                        \
	fclose(edit);                         \
	free(usablefile);                     \
}


/* HELP MENU */
#define h()																							       \
	puts("Normal:");                                             \
	puts("-p: print all tasks");                     /* pmenu */ \
	puts("-s: print all tasks from argument list");  /* smenu */ \
	puts("-n: make new task");                       /* nmenu */ \
	puts("-c: complite task as commit");             /* cmenu */ \
	puts("-r: replace task 1 and task2");            /* rmenu */ \
	puts("-e: edit task info by id");                /* emenu */ \
	puts("-l: see all task lists");                  /* lmenu */ \
	puts("-b: make a new task list");		  		       /* bmenu */ \
  puts("-m: change task list ");                   /* mmenu */ \
	puts("-k: remove the task list");                /* kmenu */ \
	puts("-a: rename a task list");                  /* amenu */ \
	puts("-u: print using task list name");          /* umenu */ \
	puts("-q: quit from task list");                 /* qmenu */ \
  puts("-h: help menu");                           /* hmenu */ \
                                                               \
	puts("\nSuper:");                                            \
	puts("-P: print from a line to b line");         /* Pmenu */ \
	puts("-S: print a-b lines from argument list");  /* Smenu */ \
	puts("-N: make +n new tasks");                   /* Nmenu */ \
	puts("-C: complite all tasks");                  /* Cmenu */ \
	puts("-E: edit with editor");                    /* Emenu */ \
	puts("-R: n-times use r");                       /* Rmenu */ \
	puts("-M: like -m, can make non-existent list"); /* Mmenu */ \
	puts("-K: like -k, can delete usable task list");/* Kmenu */

/* Super */
/* PRINT SOME TASKS FROM CURRENT TASK LIST */
#define P(fn, l1, l2) {																	                              \
	FILE *read;                                                                         \
	char c[COMLEN];																				                              \
	char b[BUFLEN];	  																		                              \
																												                              \
	if ((read = fopen(fn, "r"))) {                                                      \
		if (!(fgets(b, BUFLEN, read))) /*NO TASKS*/																				\
			puts(NOTASKS);																			                            \
		else {																								                            \
			if (l1 <= l2)																				                            \
				sprintf(c, "nl -w 1 -s ': ' -n ln \"%s\" | sed -n '%zd,%zdp'", fn, l1, l2);		\
			else																								                            \
				sprintf(c,"nl -w 1 -s ': ' -n ln \"%s\" | sed -n '%zd,%zdp' | tac",fn,l2,l1);	\
																												  \
			system(c);																					\
		}																											\
		fclose(read);\
	} else puts("Choose task list");                        \
}


/* PRINT SOME TASKS FROM CHOOSED TASK LIST */
#define S(fn, l1, l2) {                                                                 \
	FILE *read;                                                                           \
	char *ldir, *com, *buf;                                                               \
                                                                                        \
	ldir = malloc(DIRLEN);                                                                \
	buf  = malloc(BUFLEN);                                                                \
	com  = malloc(COMLEN);                                                                \
                                                                                        \
	gethomepath(ldir);                                                                    \
	strcat(ldir, "/.tasks/");                                                             \
	strcat(ldir, fn);                                                                     \
																												                                \
	if ((read = fopen(ldir, "r"))) {                                                      \
		if (!(fgets(buf, BUFLEN, read))) /*NO TASKS*/                                       \
			puts(NOTASKS);																			                              \
		else {																								                              \
			if (l1 <= l2)																				                              \
				sprintf(com, "nl -w 1 -s ': ' -n ln \"%s\" | sed -n '%zd,%zdp'", ldir, l1, l2);	\
			else																								                              \
				sprintf(com,"nl -w 1 -s ': ' -n ln \"%s\" | sed -n '%zd,%zdp' | tac",ldir,l2,l1);\
																												                                \
			system(com);  																			                              \
		}																											                              \
		fclose(read);                                                                       \
	} else puts("Choose task list");                                                      \
                                                                                        \
	free(ldir); free(buf); free(com);                                                     \
}


/* MAKE N-TIMES TASKS IN CURRENT TASK LIST*/
#define N(filename, len_mac) {			  \
	FILE *tasks, *read;                 \
	char b[BUFLEN];									    \
	size_t len;												  \
																		  \
	if ((read = fopen(filename, "r"))) {\
		tasks = fopen(filename, "a");     \
		for (len = len_mac; len--;) {			\
			fgets(b, TASKLEN, stdin);				\
			fputs(b, tasks);								\
		}																	\
		fclose(tasks); fclose(read);      \
	} else                              \
		puts("Choose a task list");       \
}


/* COMPLETE ALL TASKS FROM CURRENT TASK LIST */
#define C(filename) {						        \
	FILE *read;                           \
				                                \
	if ((read = fopen(filename, "r"))) {  \
		remove(filename);		      					\
		make(filename);                   	\
		fclose(read);                       \
	} else                                \
		puts("Choose an usable task list"); \
}


/* EDIT TASK LIST WITH EDITOR(DEFAULT IS NANO) */
#define E(listdir) {                         \
	FILE *r;                                   \
	char *com;                                 \
                                             \
	com = malloc(COMLEN);                      \
	if ((r = fopen(listdir, "r"))) {           \
		sprintf(com,"%s \"%s\"",EDITOR,listdir); \
		system(com);                             \
		fclose(r);                               \
	} else puts("Choose a task list");         \
                                             \
	free(com);                                 \
}


/* REPLACE SOME TASKS N-TIMES FROM CURRENT TASK LIST */
#define R(fn, times) {									\
	size_t l1, l2, i;											\
	for (i = 1; i <= times; i++) {				\
		scanf("%zu %zu", &l1, &l2);					\
		replace(fn, l1, l2);								\
	}																			\
}																				\


/* MOVE TO OTHER TASK LIST. IF IT DOESN'T EXIST TASKS WOULD MADE IT */
#define M(list) {                       \
	FILE *w;                              \
	char *listdir, *usabledir;            \
                                        \
	listdir   = malloc(DIRLEN);           \
	usabledir = malloc(DIRLEN);           \
                                        \
	gethomepath(listdir);                 \
	strcat(listdir, "/.tasks/");          \
	strcat(listdir, list);                \
                                        \
	gethomepath(usabledir);               \
	strcat(usabledir, "/.tasks/.usable"); \
                                        \
	if (access(listdir, F_OK) == -1)      \
		{make(listdir);}                    \
	w = fopen(usabledir, "w");						\
	fputs(list, w);												\
                                        \
	fclose(w);                            \
	free(listdir);                        \
	free(usabledir);                      \
}


/* KILL TASK LIST WITHOUT A RESTRICTIONS */
#define K(usepath, tokill) {                         \
	FILE *usablef, *read;                              \
	char *listdir, *usinglist, *usabledir;             \
                                                     \
	listdir   = malloc(DIRLEN);                        \
	usabledir = malloc(DIRLEN);                        \
	usinglist = malloc(BUFLEN);                        \
                                                     \
	gethomepath(usabledir);                            \
	strcat(usabledir, "/.tasks/.usable");              \
	read = fopen(usabledir, "r");                      \
	fgets(usinglist, BUFLEN, read);                    \
	                                                   \
	gethomepath(listdir);                              \
	strcat(listdir, "/.tasks/");                       \
	strcat(listdir, tokill);                           \
                                                     \
	if (strcmp(tokill, NONPATH) == 0)                  \
		puts("\"Nothing\" is not a task list");          \
	else if (strcmp(usinglist,tokill) == 0) {          \
		puts("Complete! Change your task list");         \
		fputs(NONPATH, (usablef = fopen(usabledir,"w")));\
		fclose(usablef);                                 \
	}                                                  \
	remove(listdir);                                   \
	                                                   \
	fclose(read);                                      \
	free(listdir);                                     \
	free(usinglist);                                   \
	free(usabledir);                                   \
}
