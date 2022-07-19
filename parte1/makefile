# MAKE PARA EJECUTAR EN LA PC

CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld

OBJECTS = parte1.o EasyPIO.o

CFLAGS = -Wall -mcpu=arm7tdmi -g  -c
ASFLAGS = -mcpu=arm7tdmi -g 
LDFLAGS = -Ttext=0 -nostartfiles -g 

parte1.elf: $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o parte1.elf
parte1.o: parte1.c
		$(CC) $(CFLAGS) parte1.c -o parte1.o
EasyPIO.o: ../Librerias/EasyPIO_Custom.c
		$(CC) $(CFLAGS) ../Librerias/EasyPIO_Custom.c -o EasyPIO.o
clean:
		rm *.o *.elf

# MAKE PARA EJECUTAR EN LA RBI

# CC = gcc
# AS = as
# LD = ld

# OBJECTS = main.o suma.o

# CFLAGS = -Wall -g  -c
# ASFLAGS = -g 
# LDFLAGS = -g 

# suma.elf: $(OBJECTS)
#         $(CC) $(LDFLAGS) $(OBJECTS) -o suma.elf

# suma.o: suma.s 
#         $(AS) $(ASFLAGS) suma.s -o suma.o

# main.o: main.c
#         $(CC) $(CFLAGS) main.c

# clean:
#         rm *.o *.elf 