#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reserve(char *left, char *right)
{
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

void left_remove(char *p, int n, int len)
{
    reserve(p, p + n - 1);
	reserve(p + n, p + len - 1);
    reserve(p, p + len - 1);
}
int main()
{
    char arr[] = "abcdef";
    int n;
    int len = strlen(arr);
    printf("旋转前：%s\n", arr);
    printf("旋转几位:");
    scanf("%d", &n);
    while (n < 1 || n > len - 1)//对于输入旋转字符数的临界值判断，是否超过字符串长度
    {
        if (n == len)//旋转字符数为字符串长度时，旋转后的字符串与旋转前的字符串一致，所以可直接输出
        {
            printf("%s\n", arr);
            system("pause");
            return 0;
        }
        else
        {
            printf("输入错误，请重新输入\n");
            scanf("%d", &n);
        }
    }
    left_remove(arr, n, len);//函数用以完成旋转字符的功能
    printf("旋转后：%s\n", arr);
    system("pause");
    return 0;
}