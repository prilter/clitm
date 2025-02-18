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


/* DEFAULT */
#define p(fn)	{															\
	char b[TASKLEN];													\
																						\
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

#define h()																							\
	puts("Normal:");																			\
	puts("-p: print all tasks");							/* pmenu */	\
	puts("-n: make new task");								/* nmenu */	\
	puts("-c: complite task as commit");			/* cmenu */	\
	puts("-r: replace task 1 and task2");			/* rmenu */	\
	puts("-e: edit task info by id");					/* emenu */	\
	puts("-h: help menu");										/* hmenu */	\
																												\
	puts("\nSuper:");																			\
	puts("-P: print from a line to b line");	/* Pmenu */ \
	puts("-N: make +n new tasks");						/* Nmenu */	\
	puts("-C: complite all tasks");						/* Cmenu */	\
	puts("-E: edit n tasks");									/* Emenu */ \
	puts("-R: n-times use r");								/* Rmenu */	\

/* Super */
#define P(fn, l1, l2) {																	\
	char c[COMLEN];																				\
	char b[TASKLEN];																			\
																												\
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

#include <string.h>
#define N(file, len_mac) {					\
	char b[TASKLEN];									\
	size_t len;												\
																		\
	for (len = len_mac; len--;) {			\
		fgets(b, TASKLEN, stdin);				\
		fputs(b, file);									\
	}																	\
}

#define C(filename)							\
	remove(filename);							\
	fclose(fopen(filename, "a"));	\

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

