#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define ENTER 10
#define SUBIRV 'w'
#define BAJARV 's'

int main(void){
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
		n = write(fd, &tec, 1);
		if(n<0)
			printf("Error mandando el dato\n");
	}
	
	
	close(fd);
	return 0;


}
