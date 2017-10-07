// main function------>
#include"header.h"
#include"prototype.h"
int main()
{
	 printf("in function----->  %s\n",__func__);

	int choice;
	while(1)
	{
		choice = mainmenu();
		operation(choice);
	}		
	return 0;
}
