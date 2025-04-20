# CLITM
It is useful CLI Task Manager, but only a little bit :)  
  
# Refactoring report
1) One line for every case of optopt switch in main.c  
2) Made macros for -P and -S to make macros functions smaller and easer to read  
3) Renamed directory "src/operators" to "src/editfile"(this changing is more logical now)  
4) Renamed "e.c" and "r.c" to "edit.c" and "replace.c"  
  
# New updates
1) More optimizations by __attribute__(hot) and __attribute__(cold)  
2) Fixed -E bad behaivor(fixed unoptional argument)  
3) Added -P, -N, -D, -R, -b optional argument behaivor(check -h)  
4) Fixed memory allocation for is_empty function(line 23)  
5) Fixed bad stdout of empty lines for -P and -S  
6) Fixed segmentation fault for "clitm -S <listname>"  
7) Made multicompleting tasks  
For example, before u could use only this variant to complete 2,3,4 tasks:  
```bash
clitm -c 2
clitm -c 2 # Now 3 is 2
clitm -c 2 # Now 4 is 2
```  
Now you can use just a "clitm -c 2 3 4"  
8) Fixed buf when you use something like that: "clitm -S <list> 3 -l"  
  
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
