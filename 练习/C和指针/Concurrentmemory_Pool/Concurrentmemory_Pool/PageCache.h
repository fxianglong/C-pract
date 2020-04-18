#pragma once
#include"common.h"

class PageCache{
public:
	Span* NewSpan(size_t numpage);
	///��ϵͳ�����ڴ�ҵ�����������
	void SystemAllocPage(size_t numpage);
private:
	SpanList _spanLists[128];
};

static PageCache pageCacheInst;