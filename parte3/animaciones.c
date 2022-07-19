#include "animaciones.h"


int multiplicador = 1;
void auto_fantastico(int * pin){
	int retardo = 250000;
	while(1){
		for (int i = 0; i < 8; i++){
			ledsOff(pin);
			digitalWrite(pin[i], 1);
			int salir = check_keys();
			if(salir)
				return;
			usleep(retardo);
		}
		for (int i = 6; i > 0; i--){
			ledsOff(pin);
			digitalWrite(pin[i], 1);
			int salir = check_keys();
			if(salir)
				return;
			usleep(retardo);
		}
	}
}

void el_choque(int * pin){
	int retardo_base = 250000;
	int retardo = multiplicador * retardo_base;
	for (int i = 0; i < 8; i++){
		ledsOff(pin);
		digitalWrite(pin[i], 1);
		digitalWrite(pin[7 - i], 1);
		int salir = check_keys();
		if(salir)
			return;
		usleep(retardo);
	}
}

void la_apilada(int * pin){
	int i=0, j=0;
	int retardo_base = 150000;
	int retardo = multiplicador * retardo_base;
	for(i = 8; i > 0; i--){
		for(j = 0; j < i; j++){
			for(int k = 0; k < i; k++)
					digitalWrite(pin[k], 0);
			digitalWrite(pin[j], 1);
			int salir = check_keys();
			if(salir)
				return;
			usleep(retardo);
		}
		digitalWrite(pin[j-1], 0);
		int salir = check_keys();
		if(salir)
			return;
		usleep(retardo);
		digitalWrite(pin[j-1], 1);
		salir = check_keys();
		if(salir)
			return;
		usleep(retardo);
	}
}

void la_carrera(int * pin){
	int retardo_base = 250000;
	int retardo = multiplicador * retardo_base;
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
	  digitalWrite(pin[0], secuencia[i][0]);
	  digitalWrite(pin[1], secuencia[i][1]);
	  digitalWrite(pin[2], secuencia[i][2]);
	  digitalWrite(pin[3], secuencia[i][3]);
	  digitalWrite(pin[4], secuencia[i][4]);
	  digitalWrite(pin[5], secuencia[i][5]);
	  digitalWrite(pin[6], secuencia[i][6]);
	  digitalWrite(pin[7], secuencia[i][7]);
	  int salir = check_keys();
		if(salir)
			return;
	  usleep(retardo);
	}
}

void la_pareja(int * pin){
	int retardo_base = 250000;
	int retardo = multiplicador * retardo_base;
	int suma = 0;
	for(int i = 0; i <= 8; i++){
		if(suma == 3){
			suma = 0;
			i = i - 2;
		}
		for (int j = 0; j < 8; j++)
			digitalWrite(pin[j], LOW);

		if(i != 8)
				digitalWrite(pin[i], HIGH);
		if(i != 0)
				digitalWrite(pin[i-1], HIGH);
		suma++;
		int salir = check_keys();
		if(salir)
			return;
		usleep(retardo);
	}
	for (int j = 0; j < 8; j++)
		digitalWrite(pin[j], LOW);
	suma = 0;
	int salir = check_keys();
	if(salir)
		return;
	usleep(retardo);
}

void la_serpiente(int * pin){
	int retardo_base = 250000;
	int retardo = multiplicador * retardo_base;
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
	  	digitalWrite(pin[0], secuencia[i][0]);
	 	digitalWrite(pin[1], secuencia[i][1]);
	 	digitalWrite(pin[2], secuencia[i][2]);
	 	digitalWrite(pin[3], secuencia[i][3]);
	 	digitalWrite(pin[4], secuencia[i][4]);
	 	digitalWrite(pin[5], secuencia[i][5]);
	 	digitalWrite(pin[6], secuencia[i][6]);
	 	digitalWrite(pin[7], secuencia[i][7]);
		int salir = check_keys();
		if(salir)
			return;
	  usleep(retardo);
	}
}

void tiro_vertical(int * pin){
	int retardo_base = 1250000;
	int retardo = multiplicador * retardo_base;
	int x = 0;
	float v = 4.0;
	float a = -1.0;
 	float t = 0;

	for(int i=0; i < 8; i++){
		t = i/2.0;	//cuántos instantes de tiempo quiero mostrar
		x = 0;//v*t + 0.5*a*t^2;
		for(int j=0; j<8; j++)
			digitalWrite(pin[j], 0);

		digitalWrite(x, 1);
		int salir = check_keys();
		if(salir)
			return;
	}
}

void caida_pelota(int * pin){
	int retardo_base = 150000;
	int retardo = multiplicador * retardo_base;
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
	  	digitalWrite(pin[0], secuencia[i][0]);
	  	digitalWrite(pin[1], secuencia[i][1]);
	  	digitalWrite(pin[2], secuencia[i][2]);
	  	digitalWrite(pin[3], secuencia[i][3]);
	  	digitalWrite(pin[4], secuencia[i][4]);
	  	digitalWrite(pin[5], secuencia[i][5]);
	  	digitalWrite(pin[6], secuencia[i][6]);
	  	digitalWrite(pin[7], secuencia[i][7]);
		int salir = check_keys();
		if(salir)
			return;
	  	usleep(retardo);
	}
}

void ledsOff(int * pin){
  for (int j = 0; j < 8; j++)
    digitalWrite(pin[j], 0);
}

int check_keys(){
	int salir = 0;
	if(kbhit() != 0){
		char tec = getchar();
		tec = getchar();
		if(tec == 10)	//enter
			salir = 1;
	}
	
	
	/*
	if(tec == 24) //flecha arriba
		multiplicador = multiplicador + 0.1;
	if(tec == 23) //flecha abajo
		multiplicador = multiplicador - 0.1;
	*/
	return salir;
}

int kbhit()
{
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds); //STDIN_FILENO is 0
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}
