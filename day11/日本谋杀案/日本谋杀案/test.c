#include<stdio.h>
#include<stdlib.h>
int main()
{
	char killer;
	for(killer='A';killer<='D';killer++)
	{
		if(((killer!='A')+(killer=='C')+(killer=='D')+(killer!='D'))==3)
		{
			printf("������%c",killer);
			break;
		}
	}
	system("pause");
	return 0;
}