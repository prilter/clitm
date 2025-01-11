#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "/home/max/.tasks.txt"
#define TASKSLEN 100
#define TASKLEN  100
#define BUFLEN	 1024

#define checkfile(filename, mode)								\
if (!fopen(filename, mode)) {										\
		char *command = malloc(100);								\
																								\
		strcat(command, "touch ");									\
		strcat(command, filename);									\
		system(command);														\
																								\
		free(command);															\
}																								\

#define openfile(file, filename, mode)					\
	checkfile(filename, mode);										\
	file = fopen(filename, mode);									\




int edit(const char *, const char *, size_t);
int move(const char *, size_t, size_t);
int putfile(const char *);
int complete(const char *, int);
int main(int argc, char **argv)
{
	FILE *tasks;
	char *newtask;
	char mode;
	size_t id, l1, l2;

	/* REALIZE */
	checkfile(FILENAME, "a");
	newtask = malloc(TASKLEN);
	for (;(mode = getopt(argc, argv, "increh")) != -1;) {
		tasks = fopen(FILENAME, "a");
		switch (mode) {
			case 'i':
				puts("Tasks:");
				putfile(FILENAME);

				break;
			case 'n':
				fputs("New task: ", stdout);
				fgets(newtask, TASKLEN, stdin);				
				fputs(newtask, tasks);
				
				break;
			case 'c':
				fputs("COMPLETED TASK ID: ", stdout);
				scanf("%zd", &id);
			
				complete(FILENAME, id);
				break;
			case 'e':
				fputs("Line editing: ", stdout);
				scanf("%zd", &l1);

				fputs("Print new task version: ", stdout);
				scanf("%s", newtask);	

				strcat(newtask, "\n");
				edit(FILENAME, newtask, l1);
				break;
			case 'r':
				fputs("Tasks id's: ", stdout);
				scanf("%zd %zd", &l1, &l2);

				move(FILENAME, l1, l2);
				break;
			case 'h':
				puts("-i: read all tasks");						/* imenu */
				puts("-n: make new task");						/* nmenu */
				puts("-c: commit task as commit");		/* cmenu */
				puts("-r: replace task 1 and task2");	/* rmenu */
				puts("-e: edit task info by id");			/* emenu */
				puts("-h: help menu");								/* hmenu */

				break;
			case '?':
				break;
		}

		fclose(tasks);
		putchar('\n');
	}

	free(newtask);
	return 0;	
}





int complete(const char *filename, int id)
{
	FILE *file, *temp;

	openfile(file, filename, "r");
	openfile(temp, "temp.txt", "a");

	char buf[BUFLEN];
	int curline;

	for (curline = 1; fgets(buf, BUFLEN, file); ++curline)
		if (curline != id)
			fputs(buf, temp);

	fclose(file);
	fclose(temp);

	remove(filename);
	rename("temp.txt", filename);

	return 1;
}


int edit(const char *filename, const char *new, size_t cl)
{
	FILE *r, *w;
	char *buf;
	size_t i;

	if ( !(r = fopen(filename, "r")) )
		{printf("Have no \"%s\"", filename); return 0;}
	w = fopen(".temp.txt", "w");

	for (buf = malloc(BUFLEN), i = 1; fgets(buf, BUFLEN, r); i++) {
		if (i == cl) fputs(new, w);
		else				 fputs(buf, w);
	}
	free(buf);
	fclose(r);
	fclose(w);
	
	remove(filename);
	rename(".temp.txt", filename);

	return 1;
}


int move(const char *filename, size_t l1, size_t l2) 
{
	FILE *r;
	char *b1, *b2;
	size_t i;

	if (l1 == l2)
		return 1;

	if (!fopen(filename, "r"))
		{printf("Have no \"%s\"", filename); return 0;}

	b1 = malloc(TASKLEN);
 	b2 = malloc(TASKLEN);

	/* GETTING b1 AND b2 */
	r = fopen(filename, "r");
	for (i = 1; i <= l1 && fgets(b1, BUFLEN, r); i++);
	fclose(r);

	r = fopen(filename, "r");
	for (i = 0; i <= l2 && fgets(b2, BUFLEN, r); i++);
	fclose(r);

	/* MOVE */
	edit(filename, b2, l1);
	edit(filename, b1, l2);

	free(b1);
	free(b2);

	return 1;
}


int putfile(const char *filename)
{
	FILE  *file;
	char   buf[BUFLEN];
	size_t i;

	openfile(file, filename, "r");
	for (i = 1; fgets(buf, BUFLEN, file);)
		printf("%zd: %s", i++, buf);

	fclose(file);
	return 1;
}


