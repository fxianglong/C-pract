#pragma once
#include"common.h"
class CentralCache{
public:
	// �����Ļ����ȡһ�������Ķ����thread cache
	size_t FetchRangeObj(void*& start, void*& end, size_t num, size_t size);

	// ��һ�������Ķ����ͷŵ�span���
	void ReleaseListToSpans(void* start, size_t byte_size);

	// ��page cache��ȡһ��span
	Span* GetOneSpan(SpanList* list, size_t byte_size);
private:
	SpanList _spanLists[NFREE_LIST];
};

static CentralCache centralCacheInst;
