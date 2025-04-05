# Task-Manager
It's useful CLI task manager, but only a little bit :)  
  
# New updates  
1) Refactoring: added more Makefile commands, removed unusable libs, added more comments to make code more simple  
2) Have removed useless "paths" lib, use config.h file  
3) Have added configure file(config.h)  
4) Have removed install.sh. Now you can use the command "make install"(without sudo, but during the process you will need to use it)  
  
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
