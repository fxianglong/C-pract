#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<vector>
#include<unistd.h>
#include<pthread.h>
#define Num 16
class RingQueue{
private:
	std::vector<int> q;
	int cap;
	sem_t data_sem;
	sem_t space_sem;
	int consumer_step;
	int productor_step;
public:
	RingQueue(int _cap=Num):q(_cap),cap(_cap)
	{
		sem_init(&data_sem,0,0);
		sem_init(&space_sem,0,_cap);
		consumer_step = 0;
		productor_step = 0;	
	}
	~RingQueue(){
		sem_destroy(&data_sem);
		sem_destroy(&space_sem);
	}
	void PutData(const int &data){
		sem_wait(&space_sem);
		q[consumer_step] = data;
		consumer_step++;
		consumer_step %= cap;
		sem_post(&data_sem);
	}
	void GetData(int& data){
		sem_wait(&data_sem);
		data = q[productor_step];
		productor_step++;
		productor_step %= cap;
		sem_post(&space_sem);
	}
};

void *consumer(void* arg){
	RingQueue* crq = (RingQueue*)arg;
	int data;
	for(;;){
		crq->GetData(data);
		std::cout<<"consumer data:%d\n"<<data<<"\n";
		//sleep(1);
	}
}

void *productor(void* arg){
	RingQueue* prq = (RingQueue*)arg;
	srand((unsigned long)time(NULL));
	for(;;){
		int data = rand()%1024;
		prq->PutData(data);
		std::cout<<"productor data:%d\n"<<data<<"\n";
		//sleep(1);
	}
}

int main()
{
	pthread_t tid,pid;
	RingQueue rq;
	pthread_create(&pid,NULL,productor,(void*)&rq);
	pthread_create(&tid,NULL,consumer,(void*)&rq);

	pthread_join(pid,NULL);
	pthread_join(tid,NULL);
	return 0;
}






