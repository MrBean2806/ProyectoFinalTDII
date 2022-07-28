#ifndef ANIMACIONES_H
#define ANIMACIONES_H

#include "EasyPIO_Custom.h"
#include <unistd.h>
#include <math.h>

// int multiplicador = 1;

int menu();
void auto_fantastico(int *,int);
void el_choque(int *,int);
void la_apilada(int *,int);
void la_carrera(int *,int);
void la_pareja(int *,int);
void la_serpiente(int *,int);
void tiro_vertical(int *,int);
void caida_pelota(int *,int);
void ledsOff(int *);
int check_keys();
int kbhit();

#endif
