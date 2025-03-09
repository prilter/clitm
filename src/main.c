#include <getopt.h>
#include <stdlib.h>

#include "../mylibs/paths/paths.h"
#include "operators.h"
#include "../mylibs/conf/conf.h"

#define CONFDIR  "/home/max/.config/.tasks.conf"
#define FLAGS		 "P:pN:n:Cc:R:r:E:e:lb:m:k:a:h"
#define FAIL		 -1

int main(int argc, char **argv)
{
	char *taskspath;
	char mode;

	/* GET A TASKS LIST PATH */
	taskspath = malloc(TASKSLEN);
	gettaskspath(taskspath);

	/* MAIN */
	for (;(mode = getopt(argc, argv, FLAGS))!=FAIL;) {
		switch (mode) {
			case 'P':
				P(taskspath, (size_t)atoi(optarg), (size_t)atoi(argv[optind]));
				break;
			case 'p':
				p(taskspath);
				break;

			case 'N':	
				N(taskspath, atoi(optarg));
				break;
			case 'n':
				fprintf(fopen(taskspath, "a"), "%s\n", optarg);
				break;
			
			case 'C':
				C(taskspath);
				break;
			case 'c':
				complete(taskspath, atoi(optarg));
				break;
			
			case 'E':
				E(taskspath, atoi(optarg));
				break;
			case 'e':
				e(atoi(optarg), taskspath);
				break;
			
			case 'r':
				replace(taskspath, atoi(optarg), atoi(argv[optind]));
				break;
			case 'R':
				R(taskspath, atoi(optarg));
				break;

			case 'l': 
				l();
				break;
			case 'b':
				b(optarg);
				break;
			case 'm':
				m(optarg);
				break;
			case 'k':
				k(optarg);
				break;
			case 'a':
				if (*argv[optind] != '.')
					{a(taskspath, argv[optind-1], argv[optind]);}
				else
					{puts("You can't use a dot in this context");}
				break;

			case 'h':
				h();
				break;
			case '?':
				break;
		}
	}

	free(taskspath);
	return 0;	
}


