#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i = 0;
	char passkey[10]={0};
	for(i=0;i<3;i++)
	{printf("���������룺>");
	scanf("%s",&passkey);
	if( strcmp ( passkey,"12345678")==0)
	printf("��¼�ɹ�");
	else if(i<2)
		printf("�����������������\n");
	}
	if(i>3)
	{
		printf("��������˳���¼");
	}
	system("pause");
	return 0;
}
