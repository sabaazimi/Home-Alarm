CC=gcc
CFALGS=-Wall -pedandic 

main: main.o d.o libmyifttt.a
	$(CC) $(CFLAGS) main.o d.o -lwiringPi -L. -lmyifttt -lcurl -o main
main.o: main.c d.h
	$(CC) $(CFLAGS) -c -lwiringPi main.c
d.o: d.c d.h
	$(CC) $(CFLAGS) -c -lwiringPi d.c


libmyifttt.a:	ifttt.o
	ar -rcs libmyifttt.a ifttt.o

ifttt.o: 	ifttt.c ifttt.h
	$(CC) $(CFLAGS) -c -ansi $<


clean:
	rm *.o main 
