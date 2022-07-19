#include <stdio.h>
#include <termios.h>
#include <string.h>
#include <unistd.h>
#include "EasyPIO_Custom.h"
#include "animaciones.h"

#define FD_STDIN 0

#define led1 17
#define led2 27
#define led3 22
#define led4 10
#define led5 9
#define led6 11
#define led7 5
#define led8 6

int pin[8] = {led1, led2, led3, led4, led5, led6, led7, led8};

int menu();
int login();

int main(){
	if( !login() ){
		puts("Limite de intentos alcanzado");
		puts("Abortando programa...");
		//ABORTAR
	}
	

	pioInit();

	for(int i=0; i<8; i++)
		pinMode(pin[i], OUTPUT);  
	
	int op = menu();

	switch(op){
		case 1:	auto_fantastico(pin);
				break;
		case 2:	el_choque(pin);
				break;
		case 3:	la_apilada(pin);
				break;
		case 4:	la_carrera(pin);
				break;
		case 5:	la_pareja(pin);
				break;
		case 6:	la_serpiente(pin);
				break;
		case 7:	tiro_vertical(pin);
				break;
		case 8:	caida_pelota(pin);
				break;
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
