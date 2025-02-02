#include <getopt.h>
#include <stdlib.h>

#include "operators.h"

#define FILENAME "/home/max/.tasks.txt"
#define FLAGS		 "P:pN:n:Cc:r:E:e:h""
#define FAIL		 -1

int main(int argc, char **argv)
{
	FILE *tasks;
	char mode;

	/* MAIN */
	for (;(mode = getopt(argc, argv, FLAGS))!=FAIL;) {
		tasks = fopen(FILENAME, "a");
		switch (mode) {
			case 'P':
				P(FILENAME, (size_t)atoi(optarg), (size_t)atoi(argv[optind]));
				break;
			case 'p':
				p(FILENAME);
				break;

			case 'N':	
				N(tasks, atoi(optarg));
				break;
			case 'n':
				fputs(optarg, tasks);
				fputs("\n", tasks);
				break;
			
			case 'C':
				C(FILENAME);
				break;
			case 'c':
				complete(FILENAME, atoi(optarg));
				break;
			
			case 'E':
				E(FILENAME, atoi(optarg));
				break;
			case 'e':
				e(atoi(optarg), FILENAME);
				break;
			
			case 'r':
				replace(FILENAME, atoi(optarg), atoi(argv[optind]));
				break;
			/* case 'R' */

			case 'h':
				h();
				break;
			case '?':
				break;
		}
		fclose(tasks);
	}

	return 0;	
}
