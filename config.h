/* 
 * PLEASE, DON'T MAKE ANY PARAMETER(MACROSES) ELSE. 
 * YOU SHOULD USE ONLY THIS PARAMETERS. 
 * ALSO YOU CAN REMOVE THEY AND USE DEFAULT SETTINGS OF TASKS MANAGER 
*/

#define TASKSLEN   100                   /* MAX TASKS LENGTH IN TASK LIST */
#define TASKLEN    100                   /* MAX LENGTH OF TASK(<= 1024 or it can't works fine) */
#define NAMELEN    100                   /* MAX LENGTH OF NAME YOUR USABLE TASK LIST */
#define NOTASKS	   "No tasks"            /* NO TASKS TEXT RESULT */
#define EDITOR     "nano"                /* EDITOR FOR -E */
#define NONPATH    "Nothing"             /* TEXT YOU WOULD SEE IF YOU DID NOT CHOOSE TASK LIST(REFRESH BY "ctm -q") */
#define EXIST      "List does not exist" /* TEXT YOU WOULD SEE IF LIST NAME IS INVALID(TASK LIST DOES NOT EXIST) */
#define CHOOSELIST "Choose task list"    /* TEXT YOU WOULD SEE IF YOU DID NOT CHOOSE TASK LIST  */
#define TASKS      "Tasks:"              /* STDOUT OF TASK LIST */
