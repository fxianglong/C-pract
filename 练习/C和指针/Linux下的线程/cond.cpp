#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

int is_have_noodle = 0;
pthread_cond_t cond;
pthread_mutex_t mutex;
void *foodie(void *arg)
{
	while(1){
		pthread_mutex_lock(&mutex);
		while(is_have_noodle==0)
		{
			//pthread_mutex_unlock(&mutex);
			//厨师做了一碗面，唤醒吃面的人
			//pause();
			//pthread_mutex_lock(&mutex);
			//若没有面，吃面的人应该解锁，让做面的人去做面，但是解锁和休眠
			//必须是一个原子操作，因为若解锁和休眠之间被打断，厨师做面唤醒
			//吃面的人的时候，吃面的人还没有休眠，就白唤醒，但是因为没有
			//第二次唤醒，吃面的人就有可能永久休眠
			pthread_cond_wait(&cond,&mutex);
		}
		printf("noodles,delicious~~\n");
		is_have_noodle--;
		pthread_mutex_unlock(&mutex);	
		pthread_cond_signal(&cond);
		//至少唤醒一个 pthread_cond_broadcast
	}
	return NULL;
}
void *chef(void *arg)
{
	while(1){
		pthread_mutex_lock(&mutex);
		while(is_have_noodle==1){
			pthread_cond_wait(&cond,&mutex);
		}
		printf("cook noodle~~\n");
		is_have_noodle++;
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	return NULL;
}
#define MAX_FOODIE 4
int main(int argc,char *argv[])
{
	pthread_t foodie_tid,chef_tid;
	int ret = 0;
	pthread_cond_init(&cond,NULL);
	pthread_mutex_init(&mutex,NULL);
	for(int i = 0;i<MAX_FOODIE;i++){
	ret = pthread_create(&foodie_tid,NULL,foodie,NULL);
	if(ret!=0){
		printf("pthread create error\n");
		return -1;
	}
	}
	ret = pthread_create(&chef_tid,NULL,chef,NULL);
	if(ret!=0){
		printf("pthread create error\n");
		return -1;
	}
	pthread_join(foodie_tid,NULL);
	pthread_join(chef_tid,NULL);
	pthread_cond_destroy(&cond);
	pthread_mutex_destroy(&mutex);
	return 0;
}

