# CLITM
It is useful CLI Task Manager, but only a little bit :)  
  
# Refactoring report
  
# New updates
1) Added "TASKS" setting to change stdout of task list  
2) Made more safety -c  
3) Added reaction when user doesn't use any flag  
4) Changed -n argument getting to stdin(to make something like "cat file | clitm -n")  
5) Changed project name(why not?)  
  
# Plans
1) The refactoring  
2) Add more parameters to config.h  
3) Bug fix  
  
# Installation guide
```bash
git clone https://github.com/prilter/clitm
cd clitm
make install
```  
  
# Configure
1) Clone repository and move to project:  
```bash
git clone https://github.com/prilter/clitm
cd clitm
```  
2) Open config.h and configure it  
3) Setting programm  
4) Recompile:  
```bash
make release
```
