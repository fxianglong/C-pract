//手撕生产者与消费者模型
#include<iostream>
#include<queue>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MAX_QUE 10
class BlockQueue{
private:
	std::queue<int> _queue;//动态增长的队列
	int _capacity;//确定队列的最大容量
	pthread_cond_t _cond_productor;//生产者等待队列
	pthread_cond_t _cond_consumer;//消费者等待队列
	pthread_mutex_t _mutex;//用于实现互斥
public:
	BlockQueue(int que_num = MAX_QUE):_capacity(que_num){
		pthread_mutex_init(&_mutex,NULL);
		pthread_cond_init(&_cond_consumer,NULL);
		pthread_cond_init(&_cond_productor,NULL);       
	}
	~BlockQueue(){
		pthread_mutex_destroy(&_mutex);
		pthread_cond_destroy(&_cond_consumer);
		pthread_cond_destroy(&_cond_productor);
	}
	bool QueuePush(int &data){
		pthread_mutex_lock(&_mutex);//——queue是临界资源需要加锁保护
		while(_queue.size()==_capacity){//判断队列节点是否加满
			pthread_cond_wait(&_cond_productor,&_mutex);//提供给生产者的借口，数据入队
		}
		_queue.push(data);
		pthread_mutex_unlock(&_mutex);
		pthread_cond_signal(&_cond_consumer);
		return true;
	}
	//提供给消费者的借口--出队操作
	bool QueuePop(int &data){
		pthread_mutex_lock(&_mutex);
		while(_queue.empty()){//没有数据，消费者无法工作
			pthread_cond_wait(&_cond_consumer,&_mutex);
		}
		data = _queue.front();
		_queue.pop();
		pthread_mutex_unlock(&_mutex);
		pthread_cond_signal(&_cond_productor);
		return true;
	}
};  

class RingQueue{
	std::vector<int> _queue;
	int _capacity;
	int _read_step;
	int _write_step;
	sem_t _sem_lock;
	sem_t _sem_data_space;
	sem_t _sem_idle_space;
	public:
	RingQueue();
	~RingQueue();
	bool QueuePush(int &data);
	bool QueuePop(int &data);
};



void *thr_consumer(void *arg){
	BlockQueue *queue = (BlockQueue*)arg;
	while(1){
		int data;
		queue->QueuePop(data);
		printf("**get a data:%d\n",data);
	}
	return NULL;
}   
void *thr_productor(void *arg){
	int i = 0;
	BlockQueue *queue=(BlockQueue*)arg;
	while(1){
		queue->QueuePush(i);
		printf("--put a data:%d\n",i++);
	}
	return NULL;
}
#define MAX_THREAD 4
int main(int argc,char *argv[])
{
	int i,ret;
	pthread_t ctid[MAX_THREAD],ptid[MAX_THREAD];
	BlockQueue queue;
	for(i = 0;i<MAX_THREAD;i++){
		ret = pthread_create(&ctid[i],NULL,thr_consumer,(void*)&queue);
		if(ret!=0){
		std::cout<<"pthread error\n";
		return -1;
		}
	}
	for(i = 0;i<MAX_THREAD;i++){
		ret=pthread_create(&ptid[i],NULL,thr_productor,(void*)&queue);
		if(ret!=0){
			std::cout<<"pthread create error\n";
			return -1;
		}
	}
	for(int i = 0;i<MAX_THREAD;i++){
		pthread_join(ctid[i],NULL);
		pthread_join(ptid[i],NULL);
	}
	return 0;
}
