#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<pthread.h>

void *Fun1(void *p)
{
	struct sockaddr_in* addr = (struct sockaddr_in*)p;
	while (1) {
		char* ptr = inet_ntoa(addr->sin_addr);
		printf("addr1: %s\n", ptr);
		sleep(1);
	}
	return NULL; 
}

void *Fun2(void *p)
{
	struct sockaddr_in* addr = (struct sockaddr_in*)p;
	while(1){
		char* ptr = inet_ntoa(addr->sin_addr);
		printf("addr2:%s\n",ptr);
		sleep(1);
	}
	return NULL;
}

int main()
{
	pthread_t tid;
	struct sockaddr_in addr1;
	struct sockaddr_in addr2;
	addr1.sin_addr.s_addr = 0;
	addr2.sin_addr.s_addr = 0xffffffff;
	pthread_create(&tid,NULL,Fun1,&addr1);
	pthread_t tid2 = 0;
	pthread_create(&tid2,NULL,Fun2,&addr2);
	pthread_join(tid,NULL);
	pthread_join(tid2,NULL);
	return 0;
}
