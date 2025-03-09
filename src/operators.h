#include <stdio.h>

extern int edit(const char *, const char *, size_t);
extern int replace(const char *, size_t, size_t);
extern int print(const char *);
extern int complete(const char *, int);
extern int help(void);

#define TASKSLEN 100
#define TASKLEN  100
#define COMLEN	 1024
#define NOTASKS	 "No tasks"

#define make(fn) fclose(fopen(fn, "w"))

/* DEFAULT */
#define p(fn)	{															\
	char b[TASKLEN];													\
																						\
	if (!(fopen(fn, "r"))) make(fn);          \
	if (!(fgets(b, TASKLEN, fopen(fn, "r"))))	\
		puts(NOTASKS);													\
	else																			\
		{puts("Tasks:");												\
		 print(fn);}														\
}


#define e(l, filename) {												\
	char *b;																			\
	fgets((b = malloc(TASKLEN)), TASKLEN, stdin);	\
	edit(filename, b, l);													\
	free(b);																			\
}

#include <dirent.h>
#include <string.h>
#define l() {                                   \
	/* VARIABLES */                               \
	DIR  *dir;                                    \
	char *usabledir;                              \
	struct dirent *ent;                           \
                                                \
	/* GET DIR */                                 \
	usabledir = malloc(TASKSLEN);                 \
	gethomepath(usabledir);                       \
	strcat(usabledir, "/.tasks");                 \
                                                \
	/* OPEN THE DIR */                            \
	if ((dir = opendir(usabledir)) != NULL) {     \
		for (;(ent = readdir(dir));)                                 \
			if (strcmp(ent->d_name, "usable") && *(ent->d_name) != '.')\
				{puts(ent->d_name);}                    \
	} else                                        \
		{puts("We lost your tasks lists. Sorry");}  \
                                                \
	closedir(dir);                                \
	free(usabledir);                              \
}


#define b(list) {             \
	char *listdir;              \
                              \
	listdir = malloc(TASKSLEN); \
	gethomepath(listdir);       \
	strcat(listdir, "/.tasks/");\
	strcat(listdir, list);      \
                              \
	fopen(listdir, "w");        \
	free(listdir);              \
}


#include <unistd.h>
#define m(list) {\
	FILE *w;                              \
	char *listdir, *usabledir;            \
                                        \
	listdir   = malloc(TASKSLEN);         \
	usabledir = malloc(TASKSLEN);         \
                                        \
	gethomepath(listdir);                 \
	strcat(listdir, "/.tasks/");          \
	strcat(listdir, list);                \
                                        \
	gethomepath(usabledir);               \
	strcat(usabledir, "/.tasks/usable");  \
                                        \
	if (access(listdir, F_OK) != -1) {    \
		w = fopen(usabledir, "w");          \
		fputs(list, w);                     \
	} else {printf("Make %s list", list);}\
                                        \
	free(listdir);                        \
	free(usabledir);                      \
}


#define k(list) {                                    \
	char *listdir, *usinglist, *usabledir;             \
                                                     \
	listdir   = malloc(TASKSLEN);                      \
	usabledir = malloc(TASKSLEN);                      \
	usinglist = malloc(TASKSLEN);                      \
                                                     \
	gethomepath(usabledir);                            \
	strcat(usabledir, "/.tasks/usable");               \
	fgets(usinglist, TASKSLEN, fopen(usabledir, "r")); \
	                                                   \
	gethomepath(listdir);                              \
	strcat(listdir, "/.tasks/");                       \
	strcat(listdir, list);                             \
                                                     \
	if (strcmp(usinglist, list))/* FILE CAN NOT EXIST*/\
		remove(listdir);                                 \
	else                                               \
		puts("You can't. Change the tasks list");        \
                                                     \
	free(listdir);                                     \
	free(usinglist);                                   \
	free(usabledir);                                   \
}


#define a(tdir, oldn, newn) { \
	char *oldpath, *newpath;    \
                              \
	oldpath = malloc(TASKSLEN); \
	newpath = malloc(TASKSLEN); \
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


#define h()																							\
	puts("Normal:");                                      \
	puts("-p: print all tasks");              /* pmenu */	\
	puts("-n: make new task");                /* nmenu */	\
	puts("-c: complite task as commit");      /* cmenu */	\
	puts("-r: replace task 1 and task2");     /* rmenu */	\
	puts("-e: edit task info by id");         /* emenu */	\
	puts("-l: see all task lists");           /* lmenu */ \
	puts("-b: make a new task list");		  		/* bmenu */ \
  puts("-m: change task list ");            /* mmenu */ \
	puts("-k: remove the task list");         /* kmenu */ \
	puts("-a: rename a task list");           /* amenu */ \
  puts("-h: help menu");                    /* hmenu */	\
                                                        \
	puts("\nSuper:");                                     \
	puts("-P: print from a line to b line");  /* Pmenu */ \
	puts("-N: make +n new tasks");            /* Nmenu */	\
	puts("-C: complite all tasks");           /* Cmenu */	\
	puts("-E: edit n tasks");                 /* Emenu */ \
	puts("-R: n-times use r");                /* Rmenu */	\

/* Super */
#define P(fn, l1, l2) {																	\
	char c[COMLEN];																				\
	char b[TASKLEN];																			\
																												\
	if (!fopen(fn, "r")) make(fn);                        \
	if (!(fgets(b, TASKLEN, fopen(fn, "r")))) /*NO TASKS*/\
		puts(NOTASKS);																			\
	else {																								\
		if (l1 <= l2)																				\
			sprintf(c, "nl -w 1 -s ': ' -n ln %s | sed -n '%zd,%zdp'", fn, l1, l2);		\
		else																								\
			sprintf(c,"nl -w 1 -s ': ' -n ln %s | sed -n '%zd,%zdp' | tac",fn,l2,l1);	\
																												\
		system(c);																					\
	}																											\
}

#define N(filename, len_mac) {			\
	FILE *tasks;                      \
	char b[TASKLEN];									\
	size_t len;												\
																		\
	tasks = fopen(filename, "a");     \
	for (len = len_mac; len--;) {			\
		fgets(b, TASKLEN, stdin);				\
		fputs(b, tasks);								\
	}																	\
}

#define C(filename)							\
	if (!fopen(filename, "r"))    \
		make(filename);             \
	remove(filename);							\
	fopen(filename, "a");        	\

#define E(fn, times) {							\
	char	*newt;											\
	size_t l, tms;										\
																		\
	newt = malloc(TASKLEN);						\
	for (tms = times; tms--;) {				\
		fputs("Line editing: ", stdout);\
		scanf("%zu", &l);								\
																		\
		fputs("New: ", stdout);					\
		scanf("%s", newt);							\
																		\
		strcat(newt, "\n");							\
		edit(fn, newt, l);							\
	}																	\
	free(newt);												\
}

#define R(fn, times) {									\
	size_t l1, l2, i;											\
	for (i = 1; i <= times; i++) {				\
		scanf("%zu %zu", &l1, &l2);					\
		replace(fn, l1, l2);								\
	}																			\
}																				\

