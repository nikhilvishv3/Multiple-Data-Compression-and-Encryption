// this is decompression function
#include"header.h"
#include"prototype.h"
int decompression()
{
	printf("in function ----->%s\n",__func__);
	int fd,ndc,l;
	fd = open("compression",O_RDONLY);
	printf("fd is--------->%d",fd);
	ndc=lseek(fd,0,SEEK_END);
	l = codelength(ndc);
	printf("the length of master arry for codelength is ----%d\n",ndc);	
	printf("the codelength is ---->%d\n",l);
	switch(l)
	{
		case 2:
			decompression2();
			break;
		case 3:
			decompression3();
			break;
		case 4:
			decompression4();
			break;
		case 5:
			decompression5();
			break;
		case 6:
			decompression6();
			break;
		case 7:
			decompression7();
			break;
		default:
			printf("\"This file cannot be decompressed or may be some error\"");
			break;
	}
	return 0;
}

