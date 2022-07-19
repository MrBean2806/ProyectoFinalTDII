CC = gcc
AS = as
LD = ld

OBJECTS = parte4.o animaciones.o EasyPIO.o

CFLAGS = -Wall -g  -c
ASFLAGS = -g 
LDFLAGS = -g 

parte4.elf: $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o parte4.elf

parte4.o: parte4.c
		$(CC) $(CFLAGS) parte4.c -o parte4.o

animaciones.o: animaciones.c
		$(CC) $(CFLAGS) animaciones.c -o animaciones.o

EasyPIO.o: EasyPIO_Custom.c
		$(CC) $(CFLAGS)	EasyPIO_Custom.c -o EasyPIO.o

clean:
		rm *.o *.elf 
