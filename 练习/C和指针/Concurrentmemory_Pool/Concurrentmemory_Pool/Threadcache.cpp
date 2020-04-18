#include"Threadcache.h"
#include"CentralCache.h"
void* ThreadCache::Allocte(size_t size)
{
	size_t index = SizeClass::ListIndex(size);
	FreeList& freelist = _freeLists[index];
	if (!freelist.Empty())
	{
		return freelist.Pop();
	}
	else
	{
		return FetchFromCentralCache(size);
	}
}

void ThreadCache::Deallocte(void* ptr, size_t size)
{
	size_t index = SizeClass::ListIndex(size);
	FreeList& freeList = _freeLists[index];
	freeList.Push(ptr);

	if ()
	{
		ReleaseToCentralCache()
	}
}


///��������thread
//void* ThreadCache::FetchFromCentralCache(size_t index){
//	ģ��ȡ�ڴ����Ĵ��룬����Thread Cache���߼�
//	size_t num = 20;
//	size_t size = (index + 1) * 8;
//	char* start = (char*)malloc(size*num);
//	char* cur = start;
//	for (size_t i = 0; i < num; i++)
//	{
//		char* next = cur + size;
//		NextObj(cur)=next;
//		cur = next;
//	}
//	NextObj(cur) = nullptr;
//	
//	void* head = NextObj(start);
//	void* tail = cur;
//
//	_freeLists[index].PushRange(head,tail);
//	return start;
//}

void* ThreadCache::FetchFromCentralCache(size_t size){
	size_t num = SizeClass::NumMoveSize(size);
	//��ȡ�ڴ�
	void* start = nullptr, *end = nullptr;
	size_t actualNum = centralCacheInst.FetchRangeObj(start, end, num, size);
	if (actualNum == 1)
	{
		return start;
	}
	else
	{
		size_t index = SizeClass::_ListIndex(size);
		FreeList list = _freeLists[index];
		list.PushRange(NextObj(start),end);

		return start;
	}
}