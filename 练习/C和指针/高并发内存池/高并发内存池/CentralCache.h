#pragma once

#include"Common.h"

class CentralCache{
public:

	// �����Ļ����ȡһ�������Ķ����thread cache
	size_t FetchRangeObj(void*& start, void*& end, size_t num, size_t size);
	// ��һ�������Ķ����ͷŵ�span���
	void ReleaseListToSpans(void* start, size_t size);
	// ��spanlist����pagecache��ȡһ��span
	Span* GetOneSpan(size_t size);
private:
	SpanList _spanLists[NFREE_LIST];
};

static CentralCache centralcacheInst;//����ģʽ