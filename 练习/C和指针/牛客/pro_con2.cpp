#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#define MAX_QUE 10
class RingQueue{
private:
	std::vector<int> _queue;//使用数组实现一个环形队列
	int _capacity;//初始化环形队列的节点数量
	int _read_step;//当前读位置的数组下标
	int _write_step;//当前写位置的数组下标
	sem_t _sem_lock;//实现线程安全  锁
	sem_t _sem_con;//消费者等待队列，计数器对有数据的空间进行技术
	sem_t _sem_pro;//生产者等待队列，计数器对有空闲空间进行技术
public:
	//初始化信号量
	RingQueue(int max_que=MAX_QUE):_capacity(max_que)
	,_queue(max_que),_read_step(0),_write_step(0){
		sem_init(&_sem_lock,0,1);
		sem_init(&_sem_con,0,0);
		sem_init(&_sem_pro,0,max_que);
	}
	//销毁信号量
	~RingQueue(){
		sem_destroy(&_sem_lock);
		sem_destroy(&_sem_con);
		sem_destroy(&_sem_pro);
	}
	bool QueuePush(int &data){
		//数据入列
		//1.先加锁2.判断是否能够访问临界资源3、数据的入队操作4、数据资源的空间计数+1，环形消费者
		sem_wait(&_sem_pro);
		sem_wait(&_sem_lock);
		_queue[_write_step]=data;
		_write_step=(_write_step +1)%_capacity;
		sem_post(&_sem_lock);
		sem_post(&_sem_con);
		return true;
	}
	bool QueuePop(int &data){
		sem_wait(&_sem_con);
		sem_wait(&_sem_lock);
		data = _queue[_read_step];
		_read_step = (_read_step +1)%_capacity;
		sem_post(&_sem_lock);

		sem_post(&_sem_pro);
		return true;
	}	
};

#define MAX_THR 4

void *consumer(void *arg){
	RingQueue *queue=(RingQueue*)arg;
	while(1){
		int data;
		queue->QueuePop(data);
		printf("consumer get a data\n",data);
	}
	return NULL;
}
void *productor(void *arg){
	RingQueue *queue=(RingQueue*)arg;
	int i = 0;
	while(1){
		queue->QueuePush(i);
		printf("productor put a data%d\n",i++);
	}
	return NULL;
}
int main(){
	pthread_t ctid[MAX_THR],ptid[MAX_THR];
	RingQueue queue;

	for(int i = 0;i<MAX_THR;i++){
		int ret = pthread_create(&ctid[i],NULL,consumer,(void*)&queue);
		if(ret!=0){
			printf("thread create error\n");
			return -1;
		}
	}
	for(int i = 0;i<MAX_THR;i++){                                                                                   
		int ret = pthread_create(&ptid[i],NULL,productor,(void*)&queue);
		if(ret!=0){
			printf("thread create error\n");
			return -1;
         }
	}
	for(int i = 0;i<MAX_THR;i++){
		pthread_join(ctid[i],NULL);
		pthread_join(ptid[i],NULL);
	}	
	return 0;
}








