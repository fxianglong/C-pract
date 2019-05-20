#include<stdio.h>
#include<stdlib.h>
unsigned int reverse_bit(unsigned int value)
{
    unsigned int sum = 0;
    int i = 0;
    for (i = 0; i < 32; i++)
    {
        sum += ((value >> i) & 1) << (31 - i);//取出最低位，左移到相应位置
    }
    return sum;

}

int main()
{
    unsigned int num = 25;
    printf("反转后：%u\n", reverse_bit(num)); 
    system("pause");
	return 0;
}

