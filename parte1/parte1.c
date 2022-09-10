#include "EasyPIO_Custom.h"
#include <unistd.h>
#include <math.h>

#define led1 3
#define led2 4
#define led3 17
#define led4 18
#define led5 27
#define led6 22
#define led7 23
#define led8 24

int menu();
void auto_fantastico();
void el_choque();
void la_apilada();
void la_carrera();
void la_pareja();
void la_serpiente();
void tiro_vertical();
void caida_pelota();
void ledsOff();

int pin[8] = {led1, led2, led3, led4, led5, led6, led7, led8};

int main(void){
	pioInit();

	for(int i=0; i<8; i++)
		pinMode(pin[i], OUTPUT);  
	
	int op = menu();
	for(int i=0; i<3; i++){
		switch(op){
			case 1:	auto_fantastico();
							break;
			case 2:	el_choque();
							break;
			case 3:	la_apilada();
							break;
			case 4:	la_carrera();
							break;
			case 5:	la_pareja();
							break;
			case 6:	la_serpiente();
							break;
			case 7:	tiro_vertical();
							break;
			case 8:	caida_pelota();
							break;
		}
		ledsOff();
	}
	return 0;
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
		puts("8. ");
		scanf("%d", &op);
		if((op < 1) || (op > 8))
			puts("Secuencia no valida, intente nuevamente");
	}while((op < 1) || (op > 8));
	return op; 
}

void auto_fantastico(){
	const int retardo = 250000;
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++)
			digitalWrite(pin[j], 0);
		
		digitalWrite(pin[i], 1);
		usleep(retardo);
	}
	for (int i = 6; i > 0; i--){
		for (int j = 0; j < 8; j++)
			digitalWrite(pin[j], 0);

		digitalWrite(pin[i], 1);
		usleep(retardo);
	}
}

void el_choque(){
	const int retardo = 250000;
	for (int i = 0; i < 8; i++){
		ledsOff();

		digitalWrite(pin[i], 1);
		digitalWrite(pin[7 - i], 1);
		usleep(retardo);
	}
}

void la_apilada(){
	const int retardo = 250000;
	int i = 0, j = 0;
 	int final = 8;
 	for(j=0; j<8;j++){
		for(i=0; i<final; i++){
			digitalWrite(pin[i], 1);
			usleep(250);
			digitalWrite(pin[i], 0);
		}
		usleep(retardo);
		digitalWrite(pin[i-1], 1);
		final--;
  	}
}

void la_carrera(){
	const int retardo = 250000;
	int secuencia[18][8] = {
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0},
{0,0,1,0,0,0,0,0},
{0,0,1,0,0,0,0,0},
{0,0,0,1,0,0,0,0},
{0,0,0,1,0,0,0,0},
{1,0,0,0,1,0,0,0},
{0,1,0,0,1,0,0,0},
{0,0,1,0,0,1,0,0},
{0,0,0,1,0,1,0,0},
{0,0,0,0,1,0,1,0},
{0,0,0,0,0,1,1,0},
{0,0,0,0,0,0,1,1},
{0,0,0,0,0,0,0,1},
};
	for( int i=0; i < 18; i++){
	  digitalWrite(led1, secuencia[i][0]);
	  digitalWrite(led2, secuencia[i][1]);
	  digitalWrite(led3, secuencia[i][2]);
	  digitalWrite(led4, secuencia[i][3]);
	  digitalWrite(led5, secuencia[i][4]);
	  digitalWrite(led6, secuencia[i][5]);
	  digitalWrite(led7, secuencia[i][6]);
	  digitalWrite(led8, secuencia[i][7]);
	  usleep(retardo);
	}
}

void la_pareja(void){
	int suma;
	const int retardo = 500000;
	for (int i = 0; i <= 8; i++){
		if(suma == 3){
			suma = 0;
			i = i - 2;
		}
		ledsOff();

		if(i != 8)
				digitalWrite(pin[i], 1);
		if(i != 0)
				digitalWrite(pin[i-1], 1);
		suma++;
		usleep(retardo);
	}
	for (int j = 0; j < 8; j++)
		digitalWrite(pin[j], 0);
	suma = 0;
	usleep(retardo);
}

void la_serpiente(){
	const int retardo = 250000;
	int secuencia[][8] = {
	{1,1,1,1,0,0,0,0},
	{0,1,1,1,1,0,0,0},
	{0,0,1,1,1,1,0,0},
	{0,0,0,1,1,1,1,0},
	{0,0,0,0,1,1,1,1},
	{1,0,0,0,0,1,1,1},
	{1,1,0,0,0,0,1,1},
	{1,1,1,0,0,0,0,1},
	};

	for( int i=0; i < 8; i++){
	  digitalWrite(led1, secuencia[i][0]);
	  digitalWrite(led2, secuencia[i][1]);
	  digitalWrite(led3, secuencia[i][2]);
	  digitalWrite(led4, secuencia[i][3]);
	  digitalWrite(led5, secuencia[i][4]);
	  digitalWrite(led6, secuencia[i][5]);
	  digitalWrite(led7, secuencia[i][6]);
	  digitalWrite(led8, secuencia[i][7]);
	  usleep(retardo);
	}
}

void tiro_vertical(){
	const int retardo = 30000;
	int x = 0;  //altura, tiene un valor entre 0 y 8 (corresponde a un led)
 	float vel = 4.0;
 	float a = -1.0;
  	float t = 0;
  	float dt = 0.1; //tamaño del paso en cada ciclo
	//con estos parametros la parabola que se describe tiene una raiz en t=8
	while(t <= 8){
		x = round(vel*t + 0.5*a*t*t);
		ledsOff();
		if(x >= 1)
			digitalWrite(pin[x-1], 1);
		usleep(retardo);
		t += dt; 
  	}
}

void caida_pelota(){
	const int retardo = 250000;
	int secuencia[][8] = {
	{0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,1,0},
	{0,0,0,0,0,1,0,0},
	{0,0,0,0,0,1,0,0},
	{0,0,0,0,1,0,0,0},
	{0,0,0,0,1,0,0,0},
	{0,0,0,1,0,0,0,0},
	{0,0,1,0,0,0,0,0},
	{0,1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0},
	{0,0,0,1,0,0,0,0},
	{0,0,0,1,0,0,0,0},
	{0,0,0,0,1,0,0,0},
	{0,0,0,0,1,0,0,0},
	{0,0,0,0,1,0,0,0},
	{0,0,0,1,0,0,0,0},
	{0,0,0,1,0,0,0,0},
	{0,0,1,0,0,0,0,0},
	{0,1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0},
	{0,0,1,0,0,0,0,0},
	{0,1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0,0},
	{0,1,0,0,0,0,0,0},
	{1,0,0,0,0,0,0,0},
	};

	for( int i=0; i < 33; i++){
	  digitalWrite(led1, secuencia[i][0]);
	  digitalWrite(led2, secuencia[i][1]);
	  digitalWrite(led3, secuencia[i][2]);
	  digitalWrite(led4, secuencia[i][3]);
	  digitalWrite(led5, secuencia[i][4]);
	  digitalWrite(led6, secuencia[i][5]);
	  digitalWrite(led7, secuencia[i][6]);
	  digitalWrite(led8, secuencia[i][7]);
	  usleep(retardo);
	}
}

void ledsOff(){
  for (int j = 0; j < 8; j++)
    digitalWrite(pin[j], 0);
}
