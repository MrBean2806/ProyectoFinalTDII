#include <sys/mman.h>
#include <stdio.h>

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef EASY_PIO_H
#define EASY_PIO_H

#define BCM2835_PERI_BASE 0x3F000000
#define GPIO_BASE (BCM2835_PERI_BASE + 0x200000)

volatile unsigned int *gpio; //Pointer to base of gpio
#define GPLEV0 (* (volatile unsigned int *) (gpio + 13))
#define BLOCK_SIZE (4*1024)


#define GPFSEL ((volatile unsigned int *) (gpio + 0))
#define GPSET ((volatile unsigned int *) (gpio + 7))
#define GPCLR ((volatile unsigned int *) (gpio + 10))
#define GPLEV ((volatile unsigned int *) (gpio + 13))
#define INPUT 0
#define OUTPUT 1
#define HIGH 1
#define LOW 0

void pioInit();
void pinMode(int pin, int function);
void digitalWrite(int pin, int val);
int digitalRead(int pin);
void uartInit(int baud);
//char getCharSerial(void);
//void putCharSerial(char c);

#endif


