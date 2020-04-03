#include <stdio.h>
#include <string.h>
#include<stdlib.h>
//int main()
//{
//	char str[] = "This is a simple string";
//	char * pch;
//	pch = strstr(str, "simple");
//	strncpy(pch, "sample", 6);
//	puts(str);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	char str[] = "- This, a sample string.";
//	char * pch;
//	printf("Splitting string \"%s\" into tokens:\n", str);
//	pch = strtok(str, " ,.-");
//	while (pch != NULL)
//	{
//		printf("%s\n", pch);
//		pch = strtok(NULL, " ,.-");
//	}
//	system("pause");
//	return 0;
//}


#include <stdio.h>
#include <string.h>
//struct {
//	char name[40];
//	int age;
//} person, person_copy;
//int main()
//{
//	char myname[] = "Pierre de Fermat";
//	/* using memcpy to copy string: */
//	memcpy(person.name, myname, strlen(myname) + 1);
//	person.age = 46;
//	/* using memcpy to copy structure: */
//	memcpy(&person_copy, &person, sizeof(person));
//	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);
//	system("pause");
//	return 0;
//}

//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//union Un1
//{
//	char c[5];
//	int i;
//};
//union Un2
//{
//	short c[7];
//	int i;
//};
//
//int main(){
//	printf("%d\n", sizeof(struct S3));
//	printf("%d\n", sizeof(struct S4));
//	printf("%d\n", sizeof(struct A));
//	//下面输出的结果是什么？
//	printf("%d\n", sizeof(union Un1));
//	printf("%d\n", sizeof(union Un2));
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include<stdlib.h>
//int main()
//{
//	//代码1
//	int num = 0;
//	scanf("%d", &num);
//	int arr[10] = { 0 };
//	//代码2
//	int* ptr = NULL;
//	ptr = (int*)malloc(num*sizeof(int));
//	if (NULL != ptr)//判断ptr指针是否为空
//	{
//		int i = 0;
//		for (i = 0; i<num; i++)
//		{
//			*(ptr + i) = 0;
//		}
//	}
//	free(ptr);
//	ptr = NULL;
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//void GetMemory(char *p)
//{
//	p = (char *)malloc(100);
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//

//char p[] = "hello world";;
//char *GetMemory(void)
//{
//	//char *q = p;
//	return p;
//}
//void Test(void)
//{
//	char *str = NULL;
//	str = GetMemory();
//	printf("%s",str);
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}


//void GetMemory(char **p, int num)
//{
//	*p = (char *)malloc(num);
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//}


//void Test(void)
//{
//	char *str = (char *)malloc(100);
//	strcpy(str, "hello");
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//	free(str);
//}
//int main()
//{
//	Test();
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a[] = {2,2324,45,565,6,76,65432,};
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(&a, 7, 7, pf);//二进制的形式写到文件中
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

class Solution {
public:
	int myAtoi(string str) {
		const char *p = str.c_str();
		for (; p != nullptr && *p == ' '; p++) {}
		if (p == nullptr || (*p != '+' && *p != '-' && (*p < '0' || *p > '9'))) {
			return 0;
		}
		int res = 0, flag = 1;
		if (*p == '-') {
			flag = -1;
			p++;
		}
		else if (*p == '+') {
			p++;
		}
		int MAX = (((1 << 30) - 1) << 1) + 1;
		int MIN = -MAX - 1;
		for (; '0' <= *p && *p <= '9'; p++) {
			if ((MAX - (*p - '0')) / 10 < res) {
				if (flag == -1) {
					return MIN;
				}
				else {
					return MAX;
				}
			}
			(res *= 10) += *p - '0';
		}
		return res * flag;
	}
};