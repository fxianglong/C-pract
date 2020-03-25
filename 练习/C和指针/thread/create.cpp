#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void* thr_start(void *arg)
{
	pthread_detach(pthread_self());
	sleep(5);
//	pthread_exit(NULL);
	char *ptr="mingtianxiujia1!\n";
	pthread_exit(ptr);
	while(1){
		printf("start----%s\n",(char*)arg);
		sleep(1);
	}
	return NULL;
}
int main()
{
	pthread_t tid;
	char *ptr="this is thread\n";
	int ret = pthread_create(&tid,NULL,thr_start,(void*)ptr);
	if(ret!=0){
		perror("thread create error");
		return -1;
	}
	pthread_detach(tid);
	char* retval;
	pthread_join(tid,(void**)&retval);
	printf("retval:%s\n",retval);
	//	sleep(5);
//	pthread_cancel(3059);
	while(1){
		printf("main  thread-----%p\n",tid);
		sleep(1);
	}
	return 0;
}
