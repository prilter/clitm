compile:
	gcc src/editfile/*.c -c -std=c17
	gcc mylibs/paths/*.c -c -std=c17
	gcc mylibs/descriptor/*.c -c -std=c17
	gcc src/main.c -c -std=c17 
	rm objs/*
	mv *.o objs
	gcc objs/*.o -o clitm -std=c17
	rm clitm

debug:
	gcc src/editfile/*.c -c -Werror -Wall -Wextra -std=c17
	gcc mylibs/paths/*.c -Werror -Wall -Wextra -c -std=c17
	gcc mylibs/descriptor/*.c -Werror -Wall -Wextra -c -std=c17
	gcc src/main.c -Werror -Wall -Wextra -c -std=c17 
	rm objs/*
	mv *.o objs
	gcc objs/*.o -Werror -Wall -Werror -o clitm -std=c17
	rm clitm

codestyle:
	gcc src/editfile/*.c -c -pedantic -Wshadow -Wconversion -Wformat=2 -std=c17
	gcc mylibs/paths/*.c -pedantic -Wshadow -Wconversion -Wformat=2 -c -std=c17
	gcc mylibs/descriptor/*.c -pedantic -Wshadow -Wconversion -Wformat=2 -c -std=c17
	gcc src/main.c -pedantic -Wshadow -Wconversion -Wformat=2 -c -std=c17 
	rm objs/*
	mv *.o objs
	gcc objs/*.o -pedantic -Wshadow -Wconversion -Wformat=2 -o clitm -std=c17
	rm clitm

release:
	gcc src/editfile/*.c -O3 -c -std=c17
	gcc mylibs/paths/*.c -O3 -c -std=c17
	gcc mylibs/descriptor/*.c -O3 -c -std=c17
	gcc src/main.c -O3 -c -std=c17 
	rm objs/*
	mv *.o objs
	sudo gcc objs/*.o -O3 -o /usr/bin/clitm -std=c17

install:
	mkdir -p ~/.tasks
	echo "Nothing" > ~/.tasks/.usable
	make release
	sudo chmod 111 /usr/bin/clitm
