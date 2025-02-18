debug:
	clang src/operators/*.c -c -std=c17
	clang mylibs/conf/*.c -c -std=c17
	clang src/main.c -c -std=c17 
	clang *.o -o tasks -std=c17
	rm *.o

