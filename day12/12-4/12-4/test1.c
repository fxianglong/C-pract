#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
static void reverse(char* i,char* j)
{
	while(i<j)
	{
		char tmp = *i;
		*i = *j;
	    *j =tmp;
		i++;j--;
	}
}
void reverse_str(char arr[],int sz)
{
	char* left = arr;
	char* right = left;
	reverse(left,right+sz-2);
	printf("%s\n",arr);//��ֵȫ��
    while (*right)
    {
        if (*right == ' '&&*right != '\0') //�ҵ��ո�
        {
		reverse(left, right-1);
		right++;
		left = right++;
		}
		else right++;
    }
	reverse(left, right-1);
	printf("%s",arr);
}
int main()
{
	int sz;
	char arr[]="student a am i";
	printf("%s\n",arr);
	sz=(sizeof(arr)/sizeof(arr[0]));
	reverse_str(arr,sz);
	system("pause");
	return 0;
}