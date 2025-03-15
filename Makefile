debug:
	clang src/operators/*.c -c -std=c17
	clang mylibs/conf/*.c -c -std=c17
	clang mylibs/paths/*.c -c -std=c17
	clang src/main.c -c -std=c17 
	mv *.o objs
	clang objs/*.o -o /usr/bin/tasks -std=c17

release:
	clang src/operators/*.c -O3 -c -std=c17
	clang mylibs/conf/*.c -O3 -c -std=c17
	clang mylibs/paths/*.c -O3 -c -std=c17
	clang src/main.c -O3 -c -std=c17 
	mv *.o objs
	clang objs/*.o -O3 -o /usr/bin/tasks -std=c17


