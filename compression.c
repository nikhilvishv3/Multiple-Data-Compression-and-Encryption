// this is compression function
#include"header.h"
#include"prototype.h"

int compression()
{
	//char *m[1];
	char *str;
	int fd,l,c;
	char *m;
	 printf("in function----->  %s\n",__func__);
 	str = (char *)malloc(sizeof(char)*10);
	while(fd != 3)
	{
		printf("ENTER THE  FILE NAME :\n");
      		scanf("%s",str);
		printf("entered string is---> %s\n",str);
//		exit (0);
		fd = open(str, O_RDONLY);
		if(fd == 3)
		printf("file is opened\n");
		else
		{
			printf("invalid filename\n");
			exit (0);
		}
	}
	m = createarray(fd);
	l = strlen(m);
	printf("final length of  master array  is ---------> %d\n",l);
	printf("master arraay  is -----> %s\n",m);
	c = codelength(l);
	switch(c)
	{
		case 2:
		{
			compression2(m,l,str);
			break;
		}
		case 3:
		{
			compression3(m,l,str);
			break;
		}
		case 4:
		{
			compression4(m,str,l);
			break;
		}
		case 5:
		{
			compression5(m,l,str);
			break;
		}
		case 6:
		{
			compression6(m,l,str);
			break;
		}
		case 7:
		{
			compression7(m,l,str);
			break;
		}
		default :
		printf("IT IS ALREADY COMPRESSED!!");
	}
	
	return l;
	
}

