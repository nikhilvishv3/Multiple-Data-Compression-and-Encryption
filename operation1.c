// this is operation function
#include"header.h"
#include"prototype.h"

int operation(int c)
{
	int cl;

	printf("in function----->  %s\n",__func__);
	switch(c)
	{
		case 1:
			cl = compression();
			break;
		case 2:
			decompression(cl);
			break;
		case 3:
			exit(EXIT_FAILURE);
			break;
		default:
			printf("you entered wrong choice\n");
			break;
	}
	return 0;
}
