/* MAIN FILE(MAIN FUNCTION) */

/* INCLUDE */
#include <getopt.h>
#include <stdlib.h>

/* LIBS AND FILES(.H) */
#include "../mylibs/paths/paths.h"
#include "operators.h" 

/* LOCAL MACROSES */
#define FLAGS		 "P:pS:s:N:n:Cc:R:r:Ee:lb:M:m:K:k:a:uqh"
#define FAIL		 -1

/* MAIN FUNCTION */
int main(int argc, char **argv)
{
	/* VARIABLES */
	char *taskspath;
	int mode;

	/* GET A TASKS LIST PATH AND TASK LIST */
	taskspath = malloc(NAMELEN);
	gettaskspath(taskspath);

	/* MAIN */
	for (;(mode = getopt(argc, argv, FLAGS))!=FAIL;) {
		switch (mode) {
			case 'P':
				if (argv[optind])
					{P(taskspath, (size_t)atoi(optarg), (size_t)atoi(argv[optind]));}
				else
				  {P(taskspath, (size_t)atoi(optarg), (size_t)TASKSLEN);}
				break;
			case 'p':
				p(taskspath);
				break;

			case 's':
				s(optarg);
				break;
			case 'S':
				if (argv[optind+1])
					{S(optarg, (size_t)atoi(argv[optind]), (size_t)atoi(argv[optind+1]));}
				else 
				  {S(optarg, (size_t)atoi(argv[optind]), (size_t)TASKSLEN);}
				break;


			case 'N':	
				N(taskspath, (size_t)atoi(optarg));
				break;
			case 'n':
				if (fopen(taskspath, "r")) fprintf(fopen(taskspath, "a"), "%s\n", optarg);
				break;
			
			case 'C':
				C(taskspath);
				break;
			case 'c':
				complete(taskspath, atoi(optarg));
				break;
			
			case 'E':
				E(taskspath);
				break;
			case 'e':
				e((size_t)atoi(optarg), taskspath);
				break;
			
			case 'r':
				replace(taskspath, (size_t)atoi(optarg), (size_t)atoi(argv[optind]));
				break;
			case 'R':
				R(taskspath, (size_t)atoi(optarg));
				break;

			case 'l': 
				l();
				break;
			case 'b':
				b(optarg);
				break;

			case 'M':
				M(optarg);
				break;
			case 'm':
				m(optarg);
				break;

			case 'K':
				K(taskspath, optarg);
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
			case 'u':
				u();
				break;

			case 'q':
				q();
				break;

			case 'h':
				h();
				break;
			case '?':
				break;
		}
	}

	/* END THIS */
	free(taskspath); 
	return 0;	
}


