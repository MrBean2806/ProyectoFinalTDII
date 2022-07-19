/*
 Permita la posibilidad de controlar la velocidad de cada secuencia.
 Presionando la flecha hacia arriba se incrementará la velocidad y presionando
 la flecha hacia abajo se reducirá. Introduzca el sensado de las teclas oprimidas
 en el lugar apropiado de su programa a fin de percibir la reacción del sistema en forma inmediata,
 independiente de la velocidad actual. La velocidad ajustada en cada secuencia deberá
 conservarse entre llamadas a diferentes secuencias. */

#include "EasyPIO_Custom.h"
#include <unistd.h>
#define retardo 250000

int main(){
    //pongo la terminal en modo no canonico para leer las teclas de flechas
    struct termios t_old, t_new;
	tcgetattr(FD_STDIN, &t_old); //lee atributos del teclado
	t_new = t_old;
	t_new.c_lflag &= ~(ECHO | ICANON); // anula entrada canonica y eco
	tcsetattr(FD_STDIN,TCSANOW,&t_new); //actualiza con los valores nuevos de la config. TCSANOW = activar la modificacion inmediatamente

    

    return 0;
}

void auto_fantastico(int * pin){
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

void el_choque(int * pin){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++)
			digitalWrite(pin[j], 0);

		digitalWrite(pin[i], 1);
		digitalWrite(pin[7 - i], 1);
		usleep(retardo);
	}
}

void la_apilada(int * pin){
	for(int i = 8; i > 0; i--){
		for(int j = 0; j < i; j++){
			for(int k = 0; k < i; k++)
					digitalWrite(pin[k], 0);
			digitalWrite(pin[j], 1);
			usleep(retardo);
		}
		digitalWrite(pin[j-1], 0);
		usleep(retardo);
		digitalWrite(pin[j-1], 1);
		usleep(retardo);
	}
}

void la_carrera(int * pin){
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
	  digitalWrite(pin[1], secuencia[i][0]);
	  digitalWrite(pin[2], secuencia[i][1]);
	  digitalWrite(pin[3], secuencia[i][2]);
	  digitalWrite(pin[4], secuencia[i][3]);
	  digitalWrite(pin[5], secuencia[i][4]);
	  digitalWrite(pin[6], secuencia[i][5]);
	  digitalWrite(pin[7], secuencia[i][6]);
	  digitalWrite(pin[8], secuencia[i][7]);
	  usleep(retardo);
	}
}

void la_pareja(int * pin){
	for (int i = 0; i <= 8; i++){
		if(suma == 3){
			suma = 0;
			i = i - 2;
		}
		for (int j = 0; j < 8; j++)
			digitalWrite(pin[j], 0);

		if(i != 8)
				digitalWrite(pin[i], 1);
		if(i != 0)
				digitalWrite(pin[i-1], 1)
		suma++;
		usleep(retardo);
	}
	for (int j = 0; j < 8; j++)
		digitalWrite(pin[j], 0);
	suma = 0;
	usleep(retardo);
}

void la_serpiente(int * pin){
	int secuencia[][] = {
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
	  digitalWrite(pin[1], secuencia[i][0]);
	  digitalWrite(pin[2], secuencia[i][1]);
	  digitalWrite(pin[3], secuencia[i][2]);
	  digitalWrite(pin[4], secuencia[i][3]);
	  digitalWrite(pin[5], secuencia[i][4]);
	  digitalWrite(pin[6], secuencia[i][5]);
	  digitalWrite(pin[7], secuencia[i][6]);
	  digitalWrite(pin[8], secuencia[i][7]);
	  usleep(retardo);
	}
}

void tiro_vertical(int * pin){
	int delay = 125000;
	int x = 0;
	float v = 4.0;
	float a = -1.0;
  float t = 0;

	for(int i=0; i < 8; i++){
		t = i/2.0;	//cuántos instantes de tiempo quiero mostrar
		x = v*t + 0.5*a*t^2;
		for(int j=0; j<8; j++)
			digitalWrite(pin[j], 0);

		digitalWrite(x, 1);
	  usleep(delay);
	}
}
