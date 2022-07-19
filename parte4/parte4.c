/*
 Permita la posibilidad de controlar la velocidad de cada secuencia.
 Presionando la flecha hacia arriba se incrementará la velocidad y presionando
 la flecha hacia abajo se reducirá. Introduzca el sensado de las teclas oprimidas
 en el lugar apropiado de su programa a fin de percibir la reacción del sistema en forma inmediata,
 independiente de la velocidad actual. La velocidad ajustada en cada secuencia deberá
 conservarse entre llamadas a diferentes secuencias. */

#include <stdio.h>
#include <termios.h>
#include <string.h>
#include <unistd.h>
#include "EasyPIO_Custom.h"
#include "animaciones.h"

#define FD_STDIN 0

#define led1 2
#define led2 3
#define led3 4
#define led4 7
#define led5 27
#define led6 22
#define led7 10
#define led8 9

int pin[8] = {led1, led2, led3, led4, led5, led6, led7, led8};

int main(){
	if( !login() ){
		puts("Limite de intentos alcanzado");
		puts("Abortando programa...");
		//ABORTAR
	}

	pioInit();

	for(int i=0; i<8; i++)
		pinMode(pin[i], OUTPUT);  
	
	
	while(1)
	{
		int op = menu();

		switch(op){
			case 1:	puts("Estas viendo el auto fantastico, para salir presione ENTER");
					auto_fantastico(pin);
					break;
			case 2:	puts("Estas viendo el choque, para salir presione ENTER");
					el_choque(pin);
					break;
			case 3:	puts("Estas viendo la apilada, para salir presione ENTER");
					la_apilada(pin);
					break;
			case 4:	puts("Estas viendo la carrera, para salir presione ENTER");
					la_carrera(pin);
					break;
			case 5:	puts("Estas viendo la pareja, para salir presione ENTER");
					la_pareja(pin);
					break;
			case 6:	puts("Estas viendo la serpiente, para salir presione ENTER");
					la_serpiente(pin);
					break;
			case 7:	puts("Estas viendo el tiro vertical, para salir presione ENTER");
					tiro_vertical(pin);
					break;
			case 8:	puts("Estas viendo la caida de la pelota, para salir presione ENTER");
					caida_pelota(pin);
					break;
		}
		ledsOff(pin);
	}
	return 0;
}

//Devuelve 1 para acceso exitoso, 0 para 3 intentos fallidos
int login(){
	const char * password = "cinco";
	int intentos = 0;
	char tec = 0;
	int i = 0;
	char contra[6];
	int login = 0;		//bandera para guardar el estado de los intentos
	struct termios t_old, t_new;
	tcgetattr(FD_STDIN, &t_old); //lee atributos del teclado
	t_new = t_old;
	t_new.c_lflag &= ~(ECHO | ICANON); // anula entrada canonica y eco
	tcsetattr(FD_STDIN,TCSANOW,&t_new); //actualiza con los valores nuevos de la config. TCSANOW = activar la modificacion inmediatamente

	while(intentos < 3){
		puts("Ingrese su password de 5 digitos:");
		while (tec!=10){
			tec=getchar();
			if(i<5){
				printf("*");
				contra[i] = tec;
				i++;
			}
		}
		if( strncmp(contra, password, 5) == 0){
			login = 1;
			puts("\n---------------------------\n   Bienvenido al Sistema\n---------------------------");
			break;
		}else
			puts("\n---------------------------\n     Password invalida\n---------------------------");
		
		intentos++;
		tec = 0;
		i = 0;
	}
	tcsetattr(FD_STDIN, TCSANOW, &t_old); //actualiza con los valores previos
	return login;
}
 
int menu(){
	int op;
	do{
		puts("Seleccione la secuencia deseada [1-8]");
		puts("1. Auto fantastico");
		puts("2. El choque");
		puts("3. La apilada");
		puts("4. La carrera");
		puts("5. La pareja");
		puts("6. La serpiente");
		puts("7. Tiro vertical");
		puts("8. Caida pelota");
		scanf("%d", &op);
		if((op < 1) || (op > 8))
			puts("Secuencia no valida, intente nuevamente");
	}while((op < 1) || (op > 8));
	return op; 
}


