ex22: mat.o mymat.o debbuging.o
	gcc -g -ansi -Wall -pedantic mat.o mymat.o debbuging.c -o ex22  

mymat.o: mymat.c mat.h
	gcc -c -ansi -Wall -pedantic mymat.c -o mymat.o

mat.o: mat.c mat.h
	gcc -c -ansi -Wall -pedantic mat.c -o mat.o

debbuging.o: debbuging.c mat.h
	gcc -c -ansi -Wall -pedantic debbuging.c -o debbuging.o
