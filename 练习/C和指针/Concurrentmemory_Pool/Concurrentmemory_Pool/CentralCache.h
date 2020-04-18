#pragma once
#include"common.h"
class CentralCache{
public:
	// 从中心缓存获取一定数量的对象给thread cache
	size_t FetchRangeObj(void*& start, void*& end, size_t num, size_t size);

	// 将一定数量的对象释放到span跨度
	void ReleaseListToSpans(void* start, size_t byte_size);

	// 从page cache获取一个span
	Span* GetOneSpan(SpanList* list, size_t byte_size);
private:
	SpanList _spanLists[NFREE_LIST];
};

static CentralCache centralCacheInst;
