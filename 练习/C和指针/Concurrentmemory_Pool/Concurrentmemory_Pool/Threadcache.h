#pragma once
#include"common.h"

class ThreadCache{
public:
	//申请内存和释放内存
	void* Allocte(size_t size);
	void Deallocte(void* ptr, size_t size);
	
	//从中心获取内存
	void* FetchFromCentralCache(size_t index);
private:
	FreeList _freeLists[NFREE_LIST];
};