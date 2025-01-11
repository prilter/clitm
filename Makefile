debug:
	clang main.c -o tasks -std=c17 
release:
	gcc main.c -O3 -o tasks -std=c17
