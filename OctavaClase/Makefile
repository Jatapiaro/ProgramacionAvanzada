sumaEj : suma.o main.o
	gcc -o sumaEj suma.o main.o

main.o: sumaMain.c suma.h
	gcc -c -o main.o sumaMain.c

suma.o: suma.c suma.h
	gcc -c -o suma.o suma.c

clean: 
	@rm -f *.o
	@rm -f sumaEj
