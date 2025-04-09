/* MAIN FILE(MAIN FUNCTION) */

/* INCLUDE */
#include <getopt.h>
#include "operators.h" 

/* LOCAL MACROSES */
#define FLAGS		 "P:pS:s:N:n:Cc:R:r:E:e:lb:M:m:K:k:a:uqh"
#define ENDARGV  -1

/* MAIN FUNCTION */
int main(int argc, char **argv)
{
	int mode;
	for (;(mode = getopt(argc, argv, FLAGS))!=ENDARGV;) {
		switch (mode) {
			case 'P':
				if (argv[optind])
					{P((size_t)atoi(optarg), (size_t)atoi(argv[optind]));}
				else
				  {P((size_t)atoi(optarg), (size_t)TASKSLEN);}
				break;
			case 'p':
				p();
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
				N(atoi(optarg));
				break;
			case 'n':
				n(optarg);
				break;
			
			case 'C':
				C();
				break;
			case 'c':
				c(atoi(optarg));
				break;
			
			case 'E':
				if (*optarg == '-')
					{E(NULL);}
				else
					{E(optarg);}
				break;
			case 'e':
				e((size_t)atoi(optarg));
				break;
			
			case 'R':
				R((size_t)atoi(optarg));
				break;
			case 'r':
				r((size_t)atoi(optarg), (size_t)atoi(argv[optind]));
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
				K(optarg);
				break;
			case 'k':
				k(optarg);
				break;

			case 'a':
				if (*argv[optind] != '.')
					{a(argv[optind-1], argv[optind]);}
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
	return 0;	
}


