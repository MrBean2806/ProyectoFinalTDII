CC = gcc
AS = as
LD = ld

OBJECTS = parte6.o animaciones.o EasyPIO.o

CFLAGS = -Wall -g  -c
ASFLAGS = -g 
LDFLAGS = -g 

parte6.elf: $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o parte6.elf -lwiringPi

parte6.o: parte6.c
		$(CC) $(CFLAGS) parte6.c -o parte6.o

animaciones.o: animaciones.c
		$(CC) $(CFLAGS) animaciones.c -o animaciones.o

EasyPIO.o: EasyPIO_Custom.c
		$(CC) $(CFLAGS)	EasyPIO_Custom.c -o EasyPIO.o

clean:
		rm *.o *.elf 
