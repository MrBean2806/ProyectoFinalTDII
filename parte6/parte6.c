#include <termios.h>
#include <unistd.h>
#include "EasyPIO_Custom.h"
#include "animaciones.h"

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdlib.h>
#include <pcf8591.h>

#define Address 0x48
#define BASE 64
#define A0 BASE+0
#define A1 BASE+1
#define A2 BASE+2
#define A3 BASE+3

#define FD_STDIN 0

#define led1 17
#define led2 27
#define led3 22
#define led4 10
#define led5 9
#define led6 11
#define led7 5
#define led8 6

#define LOCAL	0
#define REMOTO	1

int modo=LOCAL; //variable global
int serial_port;

int pin[8] = {led1, led2, led3, led4, led5, led6, led7, led8};
int login(void);
int leer_ps_menu();
int eleccion_velocidad();

int main(){
	int op;
	int vel_inicial;
	
	if( !login() ){
		puts("Limite de intentos alcanzado");
		puts("Abortando programa...");
		//ABORTAR
	}

	pioInit();

	for(int i=0; i<8; i++)
		pinMode(pin[i], OUTPUT);	
	
	
	
	
	if ((serial_port = serialOpen("/dev/ttyS0", 9600)) < 0)			/* abrir el puerto serie */
	{
		printf("Unable to open serial device: %s\n", strerror (errno)) ;
		return 1 ;
  	}

	if (wiringPiSetup () == -1)							/* inicializa la configuracion de wiringPi */
	{
		printf("Unable to start wiringPi: %s\n", strerror (errno)) ;
		return 1 ;
	}
	pcf8591Setup(BASE, Address);
	  
	
	
	
	
	vel_inicial = eleccion_velocidad();
	
	printf("Seleccione modo de operación\n Para modo LOCAL, seleccione 0.\n Para modo REMOTO, seleccione 1.\n");
	scanf("%d", &modo);
	printf("Está utilizando el modo ");
	if(modo == LOCAL)
		printf("LOCAL.\n");
	else
		printf("REMOTO.\n");
	
	//seccion destinada a eleccion de la velocidad
	
	
	
	while(1)
	{
		
		
		
		
		if(modo == LOCAL)
			op = menu();
		else
			op = leer_ps_menu();

		
		
		
		switch(op){
			case 1:	puts("Estas viendo el auto fantastico, para salir presione ENTER");
					auto_fantastico(pin,vel_inicial);
					break;
			case 2:	puts("Estas viendo el choque, para salir presione ENTER");
					el_choque(pin,vel_inicial);
					break;
			case 3:	puts("Estas viendo la apilada, para salir presione ENTER");
					la_apilada(pin,vel_inicial);
					break;
			case 4:	puts("Estas viendo la carrera, para salir presione ENTER");
					la_carrera(pin,vel_inicial);
					break;
			case 5:	puts("Estas viendo la pareja, para salir presione ENTER");
					la_pareja(pin,vel_inicial);
					break;
			case 6:	puts("Estas viendo la serpiente, para salir presione ENTER");
					la_serpiente(pin,vel_inicial);
					break;
			case 7:	puts("Estas viendo el tiro vertical, para salir presione ENTER");
					tiro_vertical(pin,vel_inicial);
					break;
			case 8:	puts("Estas viendo la caida de la pelota, para salir presione ENTER");
					caida_pelota(pin,vel_inicial);
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

int leer_ps_menu()
{		
		char dat=0;
		while(dat < '1' || dat > '8')
		{
			if(serialDataAvail(serial_port)) 		/* retorna el numero de caracteres disponibles para leer o -1*/
			{
				dat = serialGetchar(serial_port);	/* retorna el siguiente caracter disponible en el dispositivo serial */
				fflush(stdin);
				//serialPutchar(serial_port, dat);	/* envia un unico byte por el puerto serie indicado*/
			}
		}
		return (int)dat - 48;
}


int eleccion_velocidad()
{
	int val;
	char tec = 0;
	int vel_inicial;
	printf("\nVelocidad inicial:\n");
	while(tec != 10)
	{
		val = analogRead(A0);
		vel_inicial = (val*9/255.0)+1;
		printf("%d \r",vel_inicial);
		if(kbhit() != 0)
		{
			tec = getchar();
		}	
	}
	
	
	printf("\nVelocidad inicial: %d\n\n",vel_inicial);

	return vel_inicial;
}










