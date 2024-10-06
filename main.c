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

				fclose(tasks);
				break;
			case 'n':
				fputs("New task: ", stdout);
				fgets(newtask, TASKLEN, stdin);				
				fputs(newtask, tasks);
				
				fclose(tasks);
				break;
			case 'c':
				fputs("COMPLETED TASK ID: ", stdout);
				scanf("%zd", &id);
			
				complete(FILENAME, id);

				fclose(tasks);	
				break;
			case 'e':
				fputs("Line editing: ", stdout);
				scanf("%zd", &l1);

				fputs("Print new task version: ", stdout);
				scanf("%s", newtask);	

				edit(FILENAME, newtask, l1);
				
				fclose(tasks);
				break;
			case 'r':
				fputs("Tasks id's: ", stdout);
				scanf("%zd %zd", &l1, &l2);

				move(FILENAME, l1, l2);

				fclose(tasks);
				break;
			case 'h':
				#define imenu "-i: read all tasks"
				#define nmenu	"-n: make new task"
				#define cmenu "-c: commit task as commit"
				#define rmenu "-r: replace task 1 and task2"
				#define emenu "-e: edit task info by id"
				#define hmenu "-h: help menu"

				puts(imenu);
				puts(nmenu);
				puts(cmenu);
				puts(rmenu);
				puts(emenu);
				puts(hmenu);

				fclose(tasks);
				break;
			case '?':
				break;
		}

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


int edit(const char *filename, const char *newinfo, size_t l1)
{
	FILE *read, *write;
	char *buf;
	size_t i;

	if ((read = fopen(filename, "r"))  && (write = fopen(".temp.txt", "w"))) {
		for (buf = malloc(BUFLEN), i = 0; fgets(buf, BUFLEN, read); i++) {
			if (i != l1-1)	fputs(buf, write);
			else						fputs(newinfo, write);
		}

		remove(filename);
		rename(".temp.txt", filename);

		free(buf);
		fclose(read);
		fclose(write);
		return 1;
	}

	printf("Undefinded system file %s", filename);
	return 0;	
}


int move(const char *filename, size_t l1, size_t l2) 
{
	FILE *read;
	char *b1, *b2;
	size_t i;

	openfile(read, filename, "r");

	b1 = malloc(TASKLEN);
 	b2 = malloc(TASKLEN);

	/* GETTING b1 AND b2 */
	if (l1 < l2) {
		for (i = 0; fgets(b1, TASKLEN, read) && i != l1-1; ++i);
		for (i = 0; fgets(b2, TASKLEN, read) && i != l2-1; ++i);
	} else if (l1 > l2) {
		for (i = 0; fgets(b2, TASKLEN, read) && i != l2-1; ++i);	
		for (i = 0; fgets(b1, TASKLEN, read) && i != l1-1; ++i);
	} else return 1;

	/* MOVE */
	edit(filename, b2, l1);
	edit(filename, b1, l2);

	free(b1);
	free(b2);
	fclose(read);
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


