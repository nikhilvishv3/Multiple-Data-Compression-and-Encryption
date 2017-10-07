// this is preserve master array function
#include"header.h"
#include"prototype.h"
int preserve_masterarray(char *m,int l)
{
	int fd1;
	fd1 = open("compression", O_RDWR);
	write(fd1, m ,l);
	close(fd1);
	return 0;
}
