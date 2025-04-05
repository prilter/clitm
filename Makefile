compile:
	gcc src/operators/*.c -c -std=c17
	gcc mylibs/paths/*.c -c -std=c17
	gcc src/main.c -c -std=c17 
	mv *.o objs
	gcc objs/*.o -o tasks -std=c17

debug:
	gcc src/operators/*.c -c -Werror -Wall -Wextra -std=c17
	gcc mylibs/paths/*.c -Werror -Wall -Wextra -c -std=c17
	gcc src/main.c -Werror -Wall -Wextra -c -std=c17 
	mv *.o objs
	gcc objs/*.o -Werror -Wall -Werror -o tasks -std=c17

codestyle:
	gcc src/operators/*.c -c -pedantic -Wshadow -Wconversion -Wformat=2 -std=c17
	gcc mylibs/paths/*.c -pedantic -Wshadow -Wconversion -Wformat=2 -c -std=c17
	gcc src/main.c -pedantic -Wshadow -Wconversion -Wformat=2 -c -std=c17 
	mv *.o objs
	gcc objs/*.o -pedantic -Wshadow -Wconversion -Wformat=2 -o tasks -std=c17

release:
	gcc src/operators/*.c -O3 -c -std=c17
	gcc mylibs/paths/*.c -O3 -c -std=c17
	gcc src/main.c -O3 -c -std=c17 
	mv *.o objs
	gcc objs/*.o -O3 -o /usr/bin/tasks -std=c17

install:
	mkdir -p ~/.tasks
	echo "Nothing" > ~/.tasks/.usable
	# chmod 700 ~/.tasks # For safity. You may don't use it
	sudo make release
