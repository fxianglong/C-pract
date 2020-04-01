#pragma once
#include<iostream>
using namespace std;
//用链表来实现内存池，每一个结点都挂有一块内存
template<typedef T>
class ObjeckPool{
	struct BlockNode//每一个节点类型
	{
		void* _memory;//指向已经分配的节点
		BlockNode* _next;//指向下一个节点
		size_t _objNum;//这块内存中对象的个数
		BlockNode(size_t ObjNum)
			:_objNum(ObjNum)
			, _next(NULL){
			_memory = malloc(_objNum*_itemSize);
		}
		~BlockNode(){
			free(_memory);
			_memory = NULL;
			_next = NULL;
			_objNum = 0;
		}
	};
public:
private:
	size_t _countIn;      //当前结点的在用的计数
	BlockNode* _frist;    //指向链表的头
	BlockNode* _last;     //指向链表的尾
	size_t _maxNum;        //记录内存块最大的容量
	static size_t _itemSize;   //单个对象的大小
	T* _lastDelete;        //指向最新释放的那个对象的空间
};