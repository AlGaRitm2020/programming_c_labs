


CC = gcc

6: 6.c
	$(CC) -o lab6 6.c

7: 7.c
	$(CC) -o lab7 7.c

5: 5.o sett.o 
	$(CC) -o lab5 5.o sett.o

5.o: 5.c sett.c
	$(CC) -c  5.c 

set.o: sett.c
	$(CC) -c  sett.c 
