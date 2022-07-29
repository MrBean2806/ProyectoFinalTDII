#include "EasyPIO_Custom.h"

void pioInit(){
 int mem_fd;
 void *reg_map;
 mem_fd = open("/dev/mem", O_RDWR|O_SYNC); // abre /dev/mem
 reg_map = mmap(
 NULL, // dir. donde comienza el mapeo (null=no importa)
 BLOCK_SIZE, // 4KB bloque mapeado
 PROT_READ|PROT_WRITE, // permite lect.y escr.en la mem.
 MAP_SHARED, // acceso no exclusivo
 mem_fd, // puntero a /dev/mem
 GPIO_BASE); // offset a la GPIO
 gpio = (volatile unsigned *)reg_map;

}

void pinMode(int pin, int function) {
 int reg = pin/10;
 int offset = (pin%10)*3;
 GPFSEL[reg] &= ~((0b111 & ~function) << offset);
 GPFSEL[reg] |= ((0b111 & function) << offset);
}

void digitalWrite(int pin, int val) {
 int reg = pin / 32;
 int offset = pin % 32;
 if (val) GPSET[reg] = 1 << offset;
 else GPCLR[reg] = 1 << offset;
}

int digitalRead(int pin) {
 int reg = pin / 32;
 int offset = pin % 32;
 return (GPLEV[reg] >> offset) & 0x00000001;
}

void uartInit(int baud) {
    /*
    uint fb = 12000000/baud; // 3 MHz UART clock
    
    pinMode(14, ALT0);
    pinMode(15, ALT0);
    UART_IBRD = fb >> 6;       // 6 Fract, 16 Int bits of BRD
    UART_FBRD = fb & 63;
    UART_LCRHbits.WLEN = 3;     // 8 Data, 1 Stop, 0 Parity, no FIFO, no Flow
    UART_CRbits.UARTEN = 1;     // Enable uart.
    */
}

char getCharSerial(void) {
    /*
    while (UART_FRbits.RXFE);    // Wait until data is available.
    return UART_DRbits.DATA;          // Return char from serial port.
    */
}


void putCharSerial(char c) {
    /*
    while (!UART_FRbits.TXFE);
    UART_DRbits.DATA = c;
    */
}
