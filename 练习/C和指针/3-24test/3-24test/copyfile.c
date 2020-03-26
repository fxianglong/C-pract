/*************************************************************************
    > File Name: copyfile.c
    > Author: fxl
    > Mail: fxianglong@163.com 
    > Created Time: 2020年03月24日 星期二 00时42分24秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	char c;
	int in,out;

	in = open("file.in",O_RDONLY);
	out = open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	while(read(in,&c,1)==1)
		write(out,&c,1);
	exit(0);
	return 0;
}
