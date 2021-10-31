BMP.out: BMP24RGBto8GS.o BMP24RGBto8GSfns.o
	gcc -Wall BMP24RGBto8GS.o BMP24RGBto8GSfns.o -o BMP.out
BMP24RGBto8GS.o: BMP24RGBto8GS.c BMP24RGBto8GSfns.h
	gcc -Wall -c BMP24RGBto8GS.c -o BMP24RGBto8GS.o
BMP24RGBto8GSfns.o: BMP24RGBto8GSfns.c BMP24RGBto8GSfns.h
	gcc -Wall -c BMP24RGBto8GSfns.c -o BMP24RGBto8GSfns.o
clean:
	rm *.o
	rm *.out