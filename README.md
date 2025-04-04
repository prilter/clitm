# Task-Manager
It's useful CLI task manager, but only a little bit :)  

# New updates  
1) Fixed bug with -P when user can't read task list if it has named with spaces  
2) Changed -E. Since now it has open by nano usable task list  
3) You can print your tasks from some moment to the end.Like this:tasks -P 3 - print everything after 2 line  
4) Added -s to print from other task list(like "tasks -s "list2")  
5) Added -S(like -P, but with difference from -s and -p)  
6) Fixed a problem to make usable file like a task list  
7) You can use "Nothing" task list  
8) Refactored the names of malloc LENS(added BUFLEN, DIRLEN...)
9) Fixed some memory leak in the working with files descriptors  
  
# Plans  
1) Add the configure file  
2) The refactoring   
  
# Installation guide  
```bash
git clone https:github.com/prilter/tasks
cd tasks
sudo ./install.sh
```
