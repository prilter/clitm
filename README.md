# CTM
It's useful CLI task manager, but only a little bit :)  
  
# Refactoring report
1) Made more easy to read p() and s() flags by is_empty() and cat() functions  
2) Made more easy to read l() flag by ls() function  
3) Made more easy to read m() and M() flags by is_exist function  
  
# New updates
1) Fixed -c bug with segmentation fault  
2) Added "descriptor.h" lib(ls.c, is_empty.c, cat.c, is_exist.c, filelen.c)  
3) Fixed bug with -R when argument more lines of file length  
4) Added -d and -D flags(check " ctm -h | grep "d   " && ctm -h | grep "D <" ")  
5) Added 2 parameters to config.h(EXIST and CHOOSELIST)  
  
# Plans
1) The refactoring  
2) Add more parameters to config.h  
3) Bug fix  
  
# Installation guide
```bash
git clone https://github.com/prilter/ctm
cd ctm
make install
```  
  
# Configure
1) Clone repository and move to project:  
```bash
git clone https://github.com/prilter/ctm
cd ctm
```  
2) Open config.h and configure it  
3) Setting programm  
4) Recompile:  
```bash
make release
```
