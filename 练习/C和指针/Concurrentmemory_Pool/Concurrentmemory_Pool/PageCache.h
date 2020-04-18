#pragma once
#include"common.h"

class PageCache{
public:
	Span* NewSpan(size_t numpage);
	///向系统申请内存挂到自由链表中
	void SystemAllocPage(size_t numpage);
private:
	SpanList _spanLists[128];
};

static PageCache pageCacheInst;