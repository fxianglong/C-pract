#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i = 0;
	char passkey[10]={0};
	for(i=0;i<3;i++)
	{printf("ÇëÊäÈëÃÜÂë£º>");
	scanf("%s",&passkey);
	if( strcmp ( passkey,"12345678")==0)
	printf("µÇÂ¼³É¹¦");
	else if(i<2)
		printf("ÊäÈë´íÎó£¬ÇëÖØĞÂÊäÈë\n");
	}
	if(i>3)
	{
		printf("ÊäÈë´íÎó£¬ÍË³öµÇÂ¼");
	}
	system("pause");
	return 0;
}
