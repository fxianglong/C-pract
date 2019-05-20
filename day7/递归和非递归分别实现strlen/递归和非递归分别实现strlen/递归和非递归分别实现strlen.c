#include<stdio.h>
#include<stdlib.h>
int my_strlen(char* string)
{
    if(* string != '\0')
	return 1+my_strlen(string+1);
	else 
		return 0;
}

int main()
{
	char string[]="rty";
	printf("%d",my_strlen(string));
	system("pause");
	return 0;
}
//#include<stdio.h>
//#include<stdlib.h>
//int my_strlen(char* string)
//{
//	int count = 0;
//	while(*string != '\0')
//	{
//		count++;
//		string++;
//	}
//	return count;
//}
//
//int main()
//{
//	char string[]="rtyqwertui";
//	printf("%d",my_strlen(string));
//	system("pause");
//	return 0;
//}
