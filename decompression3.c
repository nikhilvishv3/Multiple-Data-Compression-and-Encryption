// this is decompression of 3 byte
#include"header.h"
#include"prototype.h"
int decompression3()
{

	printf("in function----->%s\n",__func__);
	
	unsigned char *buff=NULL,ch,d,c,e,f,m;
	unsigned int efd,efd2,fd2,fd3,i=0,count,count1,length,j,n,r;	
	
	efd=open("compression",O_RDONLY);
	efd2=open("nikhil",O_RDONLY);
	fd2=open("encrypted_file",O_RDONLY);
	fd3=open("compressed_file",O_RDWR);
	

	count=lseek(efd2,0,SEEK_END); //main file nikhil
	count1=lseek(efd,0,SEEK_END); //master array
	length=lseek(fd2,0,SEEK_END); //encrypted file
	lseek(efd2,0,SEEK_SET);
	lseek(efd,0,SEEK_SET);
	lseek(fd2,0,SEEK_SET);
	printf("no. of characters in actual file && encrypted file is : %d && %d\n",count,length);
	buff=(char*)malloc(sizeof(char)*(count1));

	count1=read(efd,buff,(count1));
	printf("master array is : %s\n and no. of characters-----: %d\n",buff,count1);
	j=1,f=0; 
	while(i<length)
	{
		r =read(fd2,&ch,1);
		if(f==0)
		{
			printf("in ---->f(0)\n");	
			printf("character is read......yeah!----->%c && %d\n",ch,ch);
			c = ch;
			d = ch;
			e = ch;
			c = c >> 5;
			d = d << 3;
			d = d >> 5;
			e = e << 6;
			e = e >> 5;
			if(j<count)
			{
				write(fd3,(buff+c),1);
				printf("the written charracter is %c\n",*(buff+c));
				j++;
			}
			if(j<count)
			{
				write(fd3,(buff+d),1);
				printf("the written charracter is %c\n",*(buff+c));
				j++;
			}
		
		}
		if(f==1)
		{	
			printf("in ---->f(1)\n");	
			printf("character is read......yeah!----->%c && %d\n",ch,ch);
			c = ch;
			d = ch;
			m = ch;
			c = c >>7;
			e = e | c;
			c = ch;
			c = c << 1;
			c = c >> 5;
			d = d << 4;
			d = d >> 5;
			m = m << 7;
			m = m >> 5;
			if(j<count)
			{
				write(fd3,(buff+e),1);
				printf("the written charracter is %c\n",*(buff+e));
				j++;
			}
			if(j<count)
			{
				write(fd3,(buff+c),1);
				printf("the written charracter is %c\n",*(buff+c));
				j++;
			}
			if(j<count)
			{
				write(fd3,(buff+d),1);
				printf("the written charracter is %c\n",*(buff+d));
				j++;
			}
		
		}
		if(f==2)
		{	
			printf("in ---->f(1)\n");	
			printf("character is read......yeah!----->%c && %d\n",ch,ch);
			c = ch;
			d = ch;
			e = ch;
			c = c >> 6;
			m = m | c;
			d = d << 2;
			d = d >> 5;
			e = e << 5;
			e = e >> 5;
			if(j<count)
			{
				write(fd3,(buff+m),1);
				printf("the written charracter is %c\n",*(buff+m));
				j++;
			}
			if(j<count)
			{
				write(fd3,(buff+d),1);
				printf("the written charracter is %c\n",*(buff+d));
				j++;
			}
			if(j<count)
			{
				write(fd3,(buff+e),1);
				printf("the written charracter is %c\n",*(buff+e));
				j++;
			}
		
		}
		
	
	i++;
	f++;
	if(f==3)
	f=0;
	}
	close(fd2);
	close(fd3);
	close(efd);
	return 0;
	
}

