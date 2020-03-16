#include<iostream>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define MAX_CAP 10
class BlockQueue{
private:
	std::queue<int> _queue;
	int cap;
	pthread_mutex_t _mutex;
	pthread_cond_t pro;
	pthread_cond_t con;
public:
	void Lock(){
		pthread_mutex_lock(&_mutex);
	}
	void UnLock(){
		pthread_mutex_unlock(&_mutex);
	}
	
	void ProWait(){
		pthread_cond_wait(&pro,&_mutex);
	}
	void ConWait(){
		pthread_cond_wait(&con,&_mutex);
	}

	void SignalPro(){
		pthread_cond_signal(&pro);
	}
	void SignalCon(){
		pthread_cond_signal(&con);
	}
	
	bool IsEmpty(){
		if(_queue.size()==0)
			return true;
		return false;
	
	}
	bool IsFull(){
		if(_queue.size()==cap)
			return true;
		return false;
	}
	BlockQueue(int _cap = MAX_CAP)
	:cap(_cap)
	{
		pthread_mutex_init(&_mutex,NULL);
		pthread_cond_init(&con,NULL);
		pthread_cond_init(&pro,NULL);
	}
	~BlockQueue(){
		pthread_mutex_destroy(&_mutex);
		pthread_cond_destroy(&con);
		pthread_cond_destroy(&pro);
	}
	void PushData(const int& data){
		Lock();
		while(IsFull()){
			SignalCon();
			printf("队列已满，生产者等待\n");
			ProWait();
		}
		_queue.push(data);
		UnLock();
	}
	void PopData(int &data){
		Lock();
		while(IsEmpty()){
			SignalPro();
			printf("队列已空，消费者等待\n");
			ConWait();
		}
		data=_queue.front();
		_queue.pop();
		UnLock();
	}
};
void *productor(void* arg){
	BlockQueue* pbq = (BlockQueue*)arg;
	srand((unsigned long)time(NULL));
	for(;;){
		int data = rand()%1024;
		pbq->PushData(data);
		std::cout<<"productor data: "<<data<<"\n";
		//usleep(3000);
	}
}

void *consumer(void* arg){
	int data;
	BlockQueue* cbq=(BlockQueue*)arg;
	for(;;){
		cbq->PopData(data);
		std::cout<<"consumer data:"<<data<<"\n";
		//sleep(3000);
	}
}
#define MAX_THR 4
int main()
{
	pthread_t pid,tid;
	BlockQueue bq;
	for(int i = 0;i<MAX_THR;i++){
		pthread_create(&pid,NULL,productor,(void*)&bq);
		//std::cout<<i<<"\n";
	}
	for(int i = 0;i<MAX_THR;i++){
		pthread_create(&tid,NULL,consumer,(void*)&bq);
	//	std::cout<<i<<"\n";
	}
	pthread_join(pid,NULL);
	pthread_join(tid,NULL);

	return 0;
}
