debug:
	clang src/operators/*.c -c -std=c17
	clang src/main.c -c -std=c17 
	clang *.o -o tasks -std=c17
	rm *.o
release:
	clang src/operators/*.c -c -O3 -std=c17
	clang src/main.c -c -O3 -std=c17 
	clang *.o -o tasks -O3 -std=c17
	rm *.o

