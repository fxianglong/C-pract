#pragma once
#include<iostream>
using namespace std;
//��������ʵ���ڴ�أ�ÿһ����㶼����һ���ڴ�
template<typedef T>
class ObjeckPool{
	struct BlockNode//ÿһ���ڵ�����
	{
		void* _memory;//ָ���Ѿ�����Ľڵ�
		BlockNode* _next;//ָ����һ���ڵ�
		size_t _objNum;//����ڴ��ж���ĸ���
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
	size_t _countIn;      //��ǰ�������õļ���
	BlockNode* _frist;    //ָ�������ͷ
	BlockNode* _last;     //ָ�������β
	size_t _maxNum;        //��¼�ڴ����������
	static size_t _itemSize;   //��������Ĵ�С
	T* _lastDelete;        //ָ�������ͷŵ��Ǹ�����Ŀռ�
};