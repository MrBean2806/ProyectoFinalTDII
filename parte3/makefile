# MAKE PARA EJECUTAR EN LA PC

CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld

OBJECTS = parte3.o animaciones.o EasyPIO.o

CFLAGS = -Wall -mcpu=arm7tdmi -g  -c
ASFLAGS = -mcpu=arm7tdmi -g 
LDFLAGS = -Ttext=0 -nostartfiles -g 

parte3.elf: $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o parte3.elf

parte3.o: parte3.c
		$(CC) $(CFLAGS) parte3.c -o parte3.o

animaciones.o: ../Librerias/animaciones.c
		$(CC) $(CFLAGS) ../Librerias/animaciones.c -o animaciones.o

EasyPIO.o: EasyPIO_Custom.c
		$(CC) $(CFLAGS) ../Librerias/EasyPIO_Custom.c -o EasyPIO.o

clean:
		rm *.o *.elf

# MAKE PARA EJECUTAR EN LA RBI

# CC = gcc
# AS = as
# LD = ld

# OBJECTS = parte3.o animaciones.o EasyPIO.o

# CFLAGS = -Wall -g  -c
# ASFLAGS = -g 
# LDFLAGS = -g 

# parte3.elf: $(OBJECTS)
# 		$(CC) $(LDFLAGS) $(OBJECTS) -o parte3.elf

# parte3.o: parte3.c
# 		$(CC) $(CFLAGS) parte3.c -o parte3.o

# animaciones.o: ../Librerias/animaciones.c
# 		$(CC) $(CFLAGS) ../Librerias/animaciones.c -o animaciones.o

# EasyPIO.o: ../Librerias/EasyPIO_Custom.c
# 		$(CC) $(CFLAGS) ../Librerias/EasyPIO_Custom.c -o EasyPIO.o

# clean:
# 		rm *.o *.elf 