#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "/home/max/.tasks.txt"
#define TASKSLEN 100
#define TASKLEN  100

extern int edit(const char *, const char *, size_t);
extern int replace(const char *, size_t, size_t);
extern int print(const char *);
extern int complete(const char *, int);
extern int help(void);

int main(int argc, char **argv)
{
	FILE *tasks;
	char *newtask;
	char mode;
	size_t id, l1, l2;

	/* MAIN */
	newtask = malloc(TASKLEN);
	for (;(mode = getopt(argc, argv, "pncreh")) != -1;) {
		tasks = fopen(FILENAME, "a");
		switch (mode) {
			case 'p':
				puts("Tasks:");
				print(FILENAME);

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

				replace(FILENAME, l1, l2);
				break;
			case 'h':
				help();
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

