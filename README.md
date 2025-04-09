# CTM
It's useful CLI task manager, but only a little bit :)  
  
# Refactoring report
1) removed old path.h functions, have added more understandable functions: current_list_dir, current_list_name, list_dir, work_dir  
2) added equal macros function  
3) moved from main.c almost all libs to operators.h(it's more readable)  
4) removed c.c file and complete function, replaced by edit command  
5) removed p.c file and print function, replaced by cycles  
  
# New updates
1) fixed infinity stdin after use negative argument for -N  
2) added editing another lists for -E(temporaly need "-" argument to edit current list)  
3) Fixed bug that may interfere with using flags in a single command  
4) You can change name of usable task list  
5) Added NONPATH parametr to control stdout result if ".usable" file is empty  
6) changed help menu  
  
# Plans
1) The refactoring  
2) Fix bugs that may interfere with using flags in a single command  
  
# Installation guide
```bash
git clone https:github.com/prilter/tasks
cd tasks
make install
```  
  
# Configure
1) Clone repository and move to project:  
```bash
git clone https:github.com/prilter/tasks
cd tasks
```  
2) Open config.h and configure it  
3) Setting programm  
4) Compile:  
```bash
make install
```
