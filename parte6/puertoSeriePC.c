#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

#define FD_STDIN 0
#define ENTER 10
#define SUBIRV 'w'
#define BAJARV 's'

int main(void){
	struct termios t_old, t_new;
	tcgetattr(FD_STDIN, &t_old); //lee atributos del teclado
	t_new = t_old;
	t_new.c_lflag &= ~(ICANON); // anula entrada canonica y eco
	tcsetattr(FD_STDIN,TCSANOW,&t_new);



	int n, fd;
	//char * data;
	fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
	if(fd==-1){
		return -1;//error
		printf("Error abriendo el puerto\n");
	}
	printf("Puerto serie abierto\n");
	
	
	while(1)
	{
		char tec = getchar();
		printf("\n");
		n = write(fd, &tec, 1);
		if(n<0)
			printf("Error mandando el dato\n");
	}
	
	
	close(fd);
	tcsetattr(FD_STDIN, TCSANOW, &t_old);
	return 0;


}
