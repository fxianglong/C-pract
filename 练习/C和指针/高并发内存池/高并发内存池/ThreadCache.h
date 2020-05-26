#pragma once
#include"Common.h"
#include"CentralCache.h"
class ThreadCache{
public:
	//�����ڴ���ͷ��ڴ�
	void *Allocte(size_t size);
	void Deallocte(void* ptr, size_t size);

	//�����Ļ����ȡ����
	void* FetchFromCentralCache(size_t index);
	//������������ж�����࣬��Ҫ���ظ�centralcache
	void ListTooLong(FreeList& freeList, size_t num, size_t size);
private:
	FreeList _freeLists[NFREE_LIST];
	//ThreadCache* _next;
	//int threadid;
};

//ThreadCache* tc_list;


//�߳�TLS�����ֲ߳̾��洢
_declspec (thread) static ThreadCache* tlslist = nullptr;