//#include<stdio.h>
//#include<stdlib.h>
//#include<ctype.h>
//static int reverse(char* i,char* j)
//{
//	while(i<j)
//	{
//		char tmp = *i;
//		*i = *j;
//		*j = tmp;
//		i++;j--;
//	}
//}
//void reverse_string(char arr[],int sz)
//{
//
//	char* right = arr;
//	char* left = right;
//	while(*right)
//		{if (isspace(*right))
//        {
//            reverse(left, right - 1);//ÄæÖÃµ¥¸öµ¥´Ê
//            right++;
//            left = right;
//        }
//        else
//        {
//            right++;
//	    }
//	}
//	reverse(left ,right-1);
//	printf("%s\n",arr);
//	reverse(arr,right-1);
//}
//int main()
//{
//	char arr[] = "student a am i ";
//	int sz=sizeof(arr)/sizeof(arr[0]),i = 0;
//    printf("%s\n",arr);
//	reverse_string(arr,sz);
//	printf("%s\n",arr);
//	system("pause");
//	return 0;
//}