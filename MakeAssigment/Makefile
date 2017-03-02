flip: flip.o getopt.o
	gcc -s -o flip flip.o getopt.o
	nroff -man flip.1 > flip.man

flip.o: flip.c
	gcc -DBSD -DNDEBUG -O -c flip.c

getopt.o: getopt.c
	gcc -DBSD -DNDEBUG -O -c getopt.c

man: flip.1
	nroff -man flip.1 > flip.man

clean:
	@rm -f *.o
	@rm -f *.man
	@rm -f flip
