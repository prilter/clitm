debug:
	clang src/operators/*.c -c -std=c17
	clang mylibs/conf/*.c -c -std=c17
	clang mylibs/paths/*.c -c -std=c17
	clang src/main.c -c -std=c17 
	mv *.o objs
	clang objs/*.o -o tasks -std=c17

