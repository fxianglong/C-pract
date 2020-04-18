#include"CentralCache.h"
#include"PageCache.h"
Span* GetOneSpan(size_t size)
{
	///��ȡһ���ж����Span
	size_t index = SizeClass::_ListIndex(size);
	SpanList& spanlist = _spanLists[index];
	Span* it = spanlist.Begin();
	while (it != spanlist.End())
	{
		if (!it->_freelist.Empty())
		{
			return it;
		}
		else
		{
			it = it->_next;
		}
	}
	//page cache��ȡһ��Span
	size_t 
	Span* span=pageCacheInst.NewSpan();

	return span;
}
///��ȡһ��
size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t num, size_t size)
{
	Span* span = GetOneSpan(size);
	FreeList& freelist = span->_freelist;

	size_t actualNum = freelist.PopRange(start, end,num);
	span->_usecount += actualNum;
	return actualNum;
}