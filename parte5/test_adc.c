/*
 
 Incluimos al codigo anterior la lectura de un canal del modulo PC8591. 
 Y mapeamos el valor del mismo a un rango de 0.1 a 1
 
 */

#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <pcf8591.h>

#define Address 0x48
#define BASE 64
#define A0 BASE+0
#define A1 BASE+1
#define A2 BASE+2
#define A3 BASE+3

int main(void){
	int val;
	if (wiringPiSetup () == -1) exit (1);	
	pcf8591Setup(BASE, Address);
	while(1)
	{
		val = analogRead(A0);
		printf("A0: %.2f ;",(val*0.9/255.0)+0.1);
		val = analogRead(A1);
		printf("A1: %d mV ;",val*3300/255);
		val = analogRead(A2);
		printf("A2: %d mV\n",val*3300/255);
		delay(300);
	}
return 0;
}


