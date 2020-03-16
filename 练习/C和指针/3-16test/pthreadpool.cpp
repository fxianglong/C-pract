#ifndef __M_TP_H__
#define __M_TP_H__
#include <iostream>
#include <queue>
#include <pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#define MAX_THREAD  5
typedef bool (*handler_t)(int);
class ThreadTask{
private:
	int _data;
	handler_t _handler;
public:
	ThreadTask():_data(-1),_handler(NULL){}
	ThreadTask(int data,handler_t handler){
		_data = data;
		_handler = handler;
	}
	void SetTask(int data,handler_t handler){
		_data = data;
		_handler = handler;
	}
	void Run(){
		_handler(_data);
	}
};

class ThreadPool{
private:
	int pthread_max;
	int pthread_cur;
	bool _tp_quit;
	std::queue<ThreadTask *> _task_queue;
	pthread_mutex_t _lock;
	pthread_cond_t _cond;
private:
	void LockQueue(){
		pthread_mutex_lock(&_lock);
	}
	void UnLockQueue(){
		pthread_mutex_unlock(&_lock);
	}

	void WakeUpOne(){
		pthread_cond_signal(&_cond);
	}
	void WakeUpAll(){
		pthread_cond_broadcast(&_cond);
	}

	void ThreadQuit(){
		pthread_cur--;
		UnLockQueue();
		pthread_exit(NULL);
	}
	void ThreadWait(){
		if(_tp_quit){
			ThreadQuit();
		}
		pthread_cond_wait(&_cond,&_lock);
	}

	bool IsEmpty(){
		return _task_queue.empty();
	}

	static void* thr_start(void* arg)
	{
		ThreadPool* tp = (ThreadPool*)arg;
		while(1){
			tp->LockQueue();
			while(tp->IsEmpty())
				tp->ThreadWait();
			ThreadTask *tt;
			tp->PopTask(&tt);
			tp->UnLockQueue();
			tt->Run();
			delete tt;
		}
		return NULL;
	}
public:
	ThreadPool(int max = MAX_THREAD):pthread_max(max),pthread_cur(max),_tp_quit(false){
		pthread_mutex_init(&_lock,NULL);
		pthread_cond_init(&_cond,NULL);
	}
	~ThreadPool(){
		pthread_mutex_destroy(&_lock);
		pthread_cond_destroy(&_cond);
	}
	bool PoolInit(){
		pthread_t tid;
		for(int i = 0;i<pthread_max;i++){
			int ret = pthread_create(&tid,NULL,thr_start,this);
			if(ret!=0){
				std::cout<<"pthread create error\n";
				return -1;
			}
		}
		return true;
	}
	bool PushTask(ThreadTask *tt){
		LockQueue();
		if (_tp_quit) {
			UnLockQueue();
			return false;
		}
		_task_queue.push(tt);
		WakeUpOne();
		UnLockQueue();
		return true;
	}
	bool PopTask(ThreadTask **tt){
		*tt = _task_queue.front();
		_task_queue.pop();
		return true;
	}
	bool PoolQuit(){
		_tp_quit = true;
		UnLockQueue();
		while(pthread_cur > 0) {
			WakeUpAll();
			usleep(1000);
		}
		return true;
	}
};
#endif

bool handler(int data)
{
	srand(time(NULL));
	int n = rand() % 5;
	printf("Thread: %p Run Tast: %d--sleep %d sec\n", pthread_self(), data, n);
	sleep(n);
	return true;
}

int main()
{
	int i;
	ThreadPool pool;
	pool.PoolInit();
	for (i = 0; i < 10; i++) {
		ThreadTask *tt = new ThreadTask(i, handler);
		pool.PushTask(tt);
	}
	    
	pool.PoolQuit();
	return 0;
}
