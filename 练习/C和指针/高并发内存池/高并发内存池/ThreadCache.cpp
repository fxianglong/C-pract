#pragma once
#include"ThreadCache.h"
#include"CentralCache.h"
void *ThreadCache::Allocte(size_t size){
	size_t index = SizeClass::ListIndex(size); // Index(size);
	FreeList& freeList = _freeLists[index];
	if (!freeList.Empty())
	{
		return freeList.Pop();
	}
	else{
		return FetchFromCentralCache(SizeClass::RoundUp(size));//size��Ҫ����
	}
}
void ThreadCache::Deallocte(void* ptr, size_t size){
	size_t index = SizeClass::ListIndex(size);//��߸�
	FreeList& freeList = _freeLists[index];
	freeList.Push(ptr);

	//�����������һ������/�ڴ��С
	size_t num = SizeClass::NumMoveSize(size);
	if (freeList.Size() >= SizeClass::NumMoveSize(size))
	{
		ListTooLong(freeList, num, size);
	}
}

void ThreadCache::ListTooLong(FreeList& freeList, size_t num, size_t size)
{
	void* start = nullptr;
	void* end = nullptr;
	freeList.PopRange(start, end, num);

	NextObj(end) = nullptr;
	centralcacheInst.ReleaseListToSpans(start, size);
}
//��������threadcache
//void* ThreadCache::FetchFromCentralCache(size_t index){
//	size_t num = 20;
//	//ģ��ȡ�ڴ����Ĵ��룬����ThreadCache���߼�
//	size_t size = (index + 1) * 8;
//	char* start = (char*)malloc(size*num);
//	char* cur = start;
//	for (int i = 0; i < num-1; i++)
//	{
//		char* next = cur + size;
//		NextObj(cur) = next;
//
//		cur = next;
//	}
//	NextObj(cur) = nullptr;
//	void* head = NextObj(start);
//	void* tail = cur;
//
//	_freeLists[index].PushRange(head,tail);
//	return start;
//}


void* ThreadCache::FetchFromCentralCache(size_t size)//size--��������Ĵ�С
{
	size_t num = SizeClass::NumMoveSize(size);
	//��ȡ�ڴ�
	void* start = nullptr;//ʧ�ܻ����쳣�����ٻ�����һ��
	void* end = nullptr;
	size_t ActualNum = centralcacheInst.FetchRangeObj(start, end, num, size);
	if (ActualNum == 1)
	{
		return start;
	}
	else//����һ������
	{
		size_t index = SizeClass::ListIndex(size);
		FreeList& list = _freeLists[index];
		list.PushRange(NextObj(start), end, ActualNum - 1);

		return start;
	}
}