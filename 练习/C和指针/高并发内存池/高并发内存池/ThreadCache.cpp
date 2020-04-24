#include"Hander.h"
#include"ThreadCache.h"

void* ThreadCache::Allocte(size_t size)
{
	size_t index = SizeClass::ListIndex(size);
	FreeList& freeList = _freeLists[index];
	if (!freeList.Empty())
	{
		return freeList.Pop();
	}
	else
	{
		return FetchFromCentralCache(SizeClass::RoundUp(size));
	}
}
void ThreadCache::Deallocte(void* ptr, size_t size)
{
	size_t index = SizeClass::ListIndex(size); // ?
	FreeList& freeList = _freeLists[index];
	freeList.Push(ptr);

	// 对象个数满足一定条件 | 内存大小
	size_t num = SizeClass::NumMoveSize(size);
	if (freeList.Num() >= num)
	{
		ListTooLong(freeList, num, size);
	}
}

void* FetchFromCentralCache(size_t index){
	size_t num = SizeClass::NumMoveSize(size);

	void* start = nullptr, *end = nullptr;
	size_t actualNum = CentralCache::GetInsatnce().FetchRangeObj(start, end, num, size);

	if (actualNum == 1)
	{
		return start;
	}
	else
	{
		size_t index = SizeClass::ListIndex(size);
		FreeList& list = _freeLists[index];
		list.PushRange(NextObj(start), end, actualNum - 1);

		return start;
	}
}

void ListTooLong(FreeList& freeList, size_t num, size_t size){
	void* start = nullptr, *end = nullptr;
	freeList.PopRange(start, end, num);

	NextObj(end) = nullptr;
	CentralCache::GetInsatnce().ReleaseListToSpans(start, size);
}