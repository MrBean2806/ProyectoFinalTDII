CC = gcc
AS = as
LD = ld

OBJECTS = parte5.o animaciones.o EasyPIO.o

CFLAGS = -Wall -g  -c
ASFLAGS = -g 
LDFLAGS = -g 

parte4.elf: $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o parte5.elf -lwiringPi

parte5.o: parte5.c
		$(CC) $(CFLAGS) parte5.c -o parte5.o

animaciones.o: animaciones.c
		$(CC) $(CFLAGS) animaciones.c -o animaciones.o

EasyPIO.o: EasyPIO_Custom.c
		$(CC) $(CFLAGS)	EasyPIO_Custom.c -o EasyPIO.o

clean:
		rm *.o *.elf 
