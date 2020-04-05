//#include<iostream>
//#include<malloc.h>
//using namespace std;
//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _data;
//
//	void* operator new(size_t n)
//	{
//		void* p = nullptr;
//		p = allocator<ListNode>().allocate(1);
//		cout << "memory pool allocate" << endl;
//		return p;
//	}
//
//	void operator delete(void* p)
//	{
//		allocator<ListNode>().deallocate((ListNode*)p, 1);
//		cout << "memory pool deallocate" << endl;
//
//	}
//};
//class List
//{
//public:
//	List()
//	{
//		_head = new ListNode;
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//
//	~List()
//	{
//		ListNode* cur = _head->_next;
//		while (cur != _head)
//		{
//			ListNode* next = cur->_next;
//			delete cur;
//			cur = next;
//		}
//
//		delete _head;
//		_head = nullptr;
//	}
//
//private:
//	ListNode* _head;
//};
//
//int main()
//{
//	List l;
//
//	return 0;
//}

//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	void* p = new char[0xfffffffful];
//	cout << "new:" << p << endl;
//	system("pause");
//	return 0;
//}

//// constructing lists
//#include <iostream>
//#include <list>
//int main()
//{
//	std::list<int> l1;                         // ����յ�l1
//	std::list<int> l2(4, 100);                 // l2�з�4��ֵΪ100��Ԫ��
//	std::list<int> l3(l2.begin(), l2.end());  // ��l2��[begin(), end()������ҿ������乹��l3
//	std::list<int> l4(l3);                    // ��l3��������l4
//
//	// ������Ϊ���������乹��l5
//	int array[] = { 16, 2, 77, 29 };
//	std::list<int> l5(array, array + sizeof(array) / sizeof(int));
//
//	// �õ�������ʽ��ӡl5�е�Ԫ��
//	for (std::list<int>::iterator it = l5.begin(); it != l5.end(); it++)
//		std::cout << *it << " ";
//	std::cout << std::endl;
//
//	for (auto& e : l5)
//		std::cout << e << " ";
//
//	std::cout << std::endl;
//	system("pause");
//	return 0;
//}



//#include <iostream>
//using namespace std;
//#include <list>
//
//int main()
//{
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	list<int> l1(array, array + sizeof(array) / sizeof(array[0]));
//
//	for (auto& e : l1)
//		cout << e << " ";
//	cout << endl;
//
//	// ��list�е�һ���ڵ������һ���ڵ��е�ֵ��Ϊ10
//	l1.front() = 10;
//	l1.back() = 10;
//
//	for (auto& e : l1)
//		cout << e << " ";
//	cout << endl;
//
//	const list<int> l2(array, array + sizeof(array) / sizeof(array[0]));
//	//int& a = l2.front();//   ��Ϊl2��const���͵�list���������front()Ϊconst ��������
//	const int& ca = l2.front();
//	system("pause");
//	return 0;
//}
//
//#include <list>
//#include<iostream>
//#include<vector>
//using namespace std;
//void PrintList(list<int>& l)
//{
//	for (auto& e : l)
//		cout << e << " ";
//	cout << endl;
//}
//
////=========================================================================================
//// push_back/pop_back/push_front/pop_front
//void TestList1()
//{
//	int array[] = { 1, 2, 3 };
//	list<int> L(array, array + sizeof(array) / sizeof(array[0]));
//
//	// ��list��β������4��ͷ������0
//	L.push_back(4);
//	L.push_front(0);
//	PrintList(L);
//
//	// ɾ��listβ���ڵ��ͷ���ڵ�
//	L.pop_back();
//	L.pop_front();
//	PrintList(L);
//}
////=========================================================================================
//// emplace_back / emplace_front / emplace
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int, int, int):" << this << endl;
//	}
//
//	Date(const Date& d)
//		: _year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{
//		cout << "Date(const Date&):" << this << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//// push_backβ�壺�ȹ����Ԫ�أ�Ȼ��Ԫ�ؿ������ڵ��У�����ʱ�ȵ����캯�����ٵ��������캯��
//// emplace_backβ�壺�ȹ���ڵ㣬Ȼ����ù��캯���ڽڵ���ֱ�ӹ������
//// emplace_back��push_back����Ч������һ�ο������캯���ĵ���
//void TestList2()
//
//{
//	list<Date> l;
//	Date d(2018, 10, 20);
//	l.push_back(d);
//	l.emplace_back(2018, 10, 21);
//	l.emplace_front(2018, 10, 19);
//}
//
////=========================================================================================
//// insert /erase 
//void TestList3()
//{
//	int array1[] = { 1, 2, 3 };
//	list<int> L(array1, array1 + sizeof(array1) / sizeof(array1[0]));
//
//	// ��ȡ�����еڶ����ڵ�
//	auto pos = ++L.begin();
//	cout << *pos << endl;
//
//	// ��posǰ����ֵΪ4��Ԫ��
//	L.insert(pos, 4);
//	PrintList(L);
//
//	// ��posǰ����5��ֵΪ5��Ԫ��
//	L.insert(pos, 5, 5);
//	PrintList(L);
//
//	// ��posǰ����[v.begin(), v.end)�����е�Ԫ��
//	vector<int> v{ 7, 8, 9 };
//	L.insert(pos, v.begin(), v.end());
//	PrintList(L);
//
//	// ɾ��posλ���ϵ�Ԫ��
//	L.erase(pos);
//	PrintList(L);
//
//	// ɾ��list��[begin, end)�����е�Ԫ�أ���ɾ��list�е�����Ԫ��
//	L.erase(L.begin(), L.end());
//	PrintList(L);
//}
//
//// resize/swap/clear
//void TestList4()
//{
//	// ������������list
//	int array1[] = { 1, 2, 3 };
//	list<int> l1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
//	PrintList(l1);
//
//	// ��l1��Ԫ�ظ������ӵ�10���������Ԫ����Ĭ��ֵ���
//	// (ע�⣺���list�з��õ����������ͣ�Ĭ��ֵΪ0, ���list�з����Զ�������Ԫ�أ�����ȱʡ���캯��)
//		l1.resize(10);
//
//	PrintList(l1);
//	// ��l1�е�Ԫ�����ӵ�20���������Ԫ����4�����
//	l1.resize(20, 4);
//	PrintList(l1);
//
//	// ��l1�е�Ԫ�ؼ��ٵ�5��
//	l1.resize(5);
//	PrintList(l1);
//
//	// ��vector�е�Ԫ��������list
//	vector<int> v{ 4, 5, 6 };
//	list<int> l2(v.begin(), v.end());
//	PrintList(l2);
//
//	// ����l1��l2�е�Ԫ��
//	l1.swap(l2);
//	PrintList(l1);
//	PrintList(l2);
//
//	// ��l2�е�Ԫ�����
//	l2.clear();
//	cout << l2.size() << endl;
//}
//
//int main()
//{
//	TestList1();
//	TestList2();
//	TestList3();
//	TestList4();
//	system("pause");
//	return 0;
//}
//#include<iostream>
//#include<list>
//using namespace std;
//void TestListIterator1()
//{
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
//
//	auto it = l.begin();
//	while (it != l.end())
//	{
//		// erase()����ִ�к�it��ָ��Ľڵ��ѱ�ɾ�������it��Ч������һ��ʹ��itʱ�������ȸ��丳ֵ
//			l.erase(it);
//		++it;
//	}
//}
//
//// ����
//void TestListIterator()
//{
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	list<int> l(array, array + sizeof(array) / sizeof(array[0]));
//	auto it = l.begin();
//	while (it != l.end())
//	{
//		l.erase(it++);    // it = l.erase(it);
//	}
//}
//int main()
//{
//	//TestListIterator1();
//	TestListIterator();
//	system("pause");
//	return 0;
//}



#include<iostream>
using namespace std;
namespace fxl{
	// List�Ľڵ���
	template<class T>
	struct ListNode{
		ListNode(const T& val=T())
		:_pPre(nullptr)
		,_pNext(nullptr)
		,_val(val){
		}
		ListNode* _pPre;
		ListNode* _pNext;
		T _val;
	};
	/*
	List �ĵ�����
	������������ʵ�ַ�ʽ��
	1. ԭ��ָ̬�룬���磺vector
	2. ��ԭ��ָ̬����з�װ�����������ʹ����ʽ��ָ����ȫ��ͬ����ˣ����Զ�������б���ʵ�����·�
	����
	1. ָ����Խ����ã������������б�������operator*()
	2. ָ�����ͨ��->��������ָ�ռ��Ա�����������б�������oprator->()
	3. ָ�����++����ƶ������������б�������operator++()��operator++(int)
	����operator--()/operator--(int)�ͷ���Ҫ���أ����ݾ���Ľṹ������˫�����������ǰ
	��               ����������Ҫ���أ������forward_list�Ͳ���Ҫ����--
	4. ��������Ҫ�����Ƿ���ȵıȽϣ���˻���Ҫ����operator==()��operator!=()
	*/
	template<class T, class Ref, class Ptr>
	class ListIterator
	{
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
	public:
		ListIterator(PNode pNode = nullptr)
			: _pNode(pNode)
		{}
		ListIterator(const Self& l)
			: _pNode(l._pNode)
		{}

		T& operator*()
		{
			return _pNode->_val;
		}

		T* operator->()
		{
			return &(operator*());
		}

		Self& operator++()
		{
			_pNode = _pNode->_pNext;
			return *this;
		}

		Self operator++(int)
		{
			Self temp(*this);
			_pNode = _pNode->_pNext;
			return temp;
		}

		bool operator!=(const Self& l)
		{
			return _pNode != l._pNode;
		}

		bool operator==(const Self& l)
		{
			return _pNode != l._pNode;
		}

		PNode _pNode;
	};
	/*
	List �ķ�������������������������������պ����෴�ģ����������++����������ǰ�ƶ����������
	��--��     �����������ƶ�����˷������������������������Ļ���֮����ʵ��
	*/
	template<class T,class Ref,class Ptr,class Iterator>
	class ListReverseIterator
	{
		typedef ListReverseIterator<T, Ref, Ptr, Iterator> Self;
		ListReverseIterator(const Iterator& it)
			:_it(it)
		{}
		ListReverseIterator(const Self& s)
			:_it(s._it){
		}
		Ref operator*(){
			Iterator temp = _it;
			return temp;
		}
		Ptr operator->(){
			return &(operator*());
		}
		// �����������++�����������������--
		Self operator++(){
			_it--;
			return *this;
		}
		Self operator++(int){
			Iterator temp(_it);
			--_it;
			return temp;
		}
		// �����������--�����������������++
		Self operator--(){
			_it++;
			return *this;
		}
		Self operator--(int){
			Iterator temp(_it);
			++_it;
			return temp;
		}
		bool operator!=(const Self& s)
		{
			return _it != s._it;
		}

		bool operator==(const Self& s)
		{
			return _it == s._it;

		}
	private:
		Iterator _it;
	};
	template<class T>
	class List{
		typedef ListNode<T> Node;
		typedef Node* PNode;

	public:
		typedef ListIterator<T, T&, T*> Iterator;
		typedef ListIterator<T, const T&, const T&> ConstIterator;
		typedef ListReverseIterator<T, T&, T*, Iterator> ReverseIterator;
		typedef ListReverseIterator<T, const T&, const T*, ConstIterator> ConstReverseIterator;
	public:
		List()
		{
			CreateHead();
		}
		List(int n, const T& value=T()){
			CreateHead();
			for (int i = 0; i < n; i++)
				PushBack(value);
		}
		template<class Iterator>
		List(Iterator first,Iterator last){
			CreateHead();
			while (first != last){
				PushBack(*first);
				first++;
			}
		}
		List(List<T>& l){
			CreateHead();
			List<T> temp(l.Begin(), l.End());
			this->Swap(temp);
		}
		List<T>& operator=(List<T>& l){
			if (this != &l)
			{
				List<T> temp(l);
				this->Swap(temp);
			}
			return *this;
		}
		~List()
		{
			Clear();
			delete _pHead;
			_pHead = nullptr;
		}
		///////////////////////////////////////////////////////////////
		// List Iterator
		Iterator Begin(){
			return Iterator(_pHead->_pNext);
		}
		Iterator End()
		{
			return Iterator(_pHead);
		}
		ReverseIterator RBegin()
		{
			return ReverseIterator(End());
		}

		ReverseIterator REnd()
		{
			return ReverseIterator(Begin());
		}

		ConstIterator CBegin()const
		{
			return ConstIterator(_pHead->_pNext);
		}

		ConstIterator CEnd()const
		{
			return ConstIterator(_pHead);
		}

		ConstReverseIterator CRBegin()const
		{
			return ConstReverseIterator(CEnd());

		}
		ConstReverseIterator CREnd()const
		{
			return ConstReverseIterator(CBegin());
		}
		///////////////////////////////////////////////////////////////
		// List Capacity
		size_t Size()const
		{
			size_t count = 0;
			PNode pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				++count;
				pCur = pCur->_pNext;
			}

			return count;
		}

		bool Empty()const
		{
			return _pHead->_pNext == _pHead;
		}

		void ReSize(size_t newSize, const T& val = T())
		{
			size_t oldSize = Size();
			if (oldSize <= newSize)
			{
				for (size_t i = oldSize; i < newSize; ++i)
					PushBack(val);
			}
			else
			{
				for (size_t i = newSize; i < oldSize; ++i)
					PopBack();
			}
		}

		////////////////////////////////////////////////////////////
		// List Access
		T& Front()
		{
			return _pHead->_pNext->_val;
		}

		const T& Front()const
		{
			return _pHead->_pNext->_val;
		}
		T& Back()
		{
			return _pHead->_pPre->_val;
		}

		const T& Back()const
		{
			return _pHead->_pPre->_val;
		}
		////////////////////////////////////////////////////////////
		// List Modify
		void PushBack(const T& val)
		{
			PNode pNewNode = new Node(val);

			// �Ȱ��½ڵ�β���ȥ
			pNewNode->_pNext = _pHead;
			pNewNode->_pPre = _pHead->_pPre;
			// ������ʣ������ָ��
			_pHead->_pPre = pNewNode;
			pNewNode->_pPre->_pNext = pNewNode;
		}

		// βɾ
		void PopBack()
		{
			// �ҵ���ɾ���ڵ�
			PNode pDel = _pHead->_pPre;
			if (pDel != _pHead)
			{
				_pHead->_pPre = pDel->_pPre;
				pDel->_pPre->_pNext = _pHead;
				delete pDel;
			}
		}

		// ͷ��
		void PushFront(const T& val)
		{
			PNode pNewNode = new Node(val);

			// �Ȱ��½ڵ�β���ȥ
			pNewNode->_pNext = _pHead->_pNext;
			pNewNode->_pPre = _pHead;
			// ������ʣ������ָ��
			_pHead->_pNext = pNewNode;
			pNewNode->_pNext->_pPre = pNewNode;
		}

		// ͷɾ
		void PopFront()
		{
			// �ҵ���ɾ���ڵ�

			PNode pDel = _pHead->_pNext;
			if (pDel != _pHead)
			{
				_pHead->_pNext = pDel->_pNext;
				pDel->_pNext->_pPre = _pHead;
				delete pDel;
			}
		}

		// ��posλ��ǰ����ֵΪval�Ľڵ�
		Iterator Insert(Iterator pos, const T& val)
		{
			PNode pNewNode = new Node(val);
			PNode pCur = pos._pNode;
			// �Ƚ��½ڵ����
			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;
			return Iterator(pNewNode);
		}

		// ɾ��posλ�õĽڵ㣬���ظýڵ����һ��λ��
		Iterator Erase(Iterator pos)
		{
			// �ҵ���ɾ���Ľڵ�
			PNode pDel = pos._pNode;
			PNode pRet = pDel->_pNext;

			// ���ýڵ�������в�������ɾ��
			pDel->_pPre->_pNext = pDel->_pNext;
			pDel->_pNext->_pPre = pDel->_pPre;
			delete pDel;

			return Iterator(pRet);
		}

		void Clear()
		{
			PNode pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				_pHead->_pNext = pCur->_pNext;
				delete pCur;
				pCur = _pHead->_pNext;
			}

			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}

		void Swap(List<T>& l)
		{

			swap(_pHead, l._pHead);
		}

	private:
		void CreateHead()
		{
			_pHead = new Node;
			_pHead->_pPre = _pHead;
			_pHead->_pNext = _pHead;
		}
	private:
		PNode _pHead;
	};
}

// �����ӡ����
template<class T>
void PrintList(fxl::List<T>& l)
{
	auto it = l.Begin();
	while (it != l.End())
	{
		cout << *it << " ";
		++it;
	}

	cout << endl;
}

// �����ӡ����
//template<class T>
//void PrintListReverse(fxl::List<T>& l)
//{
//	auto it = l.CRBegin();
//	while (it != l.CREnd())
//	{
//		cout << *it << " ";
//		++it;
//	}
//
//	cout << endl;
//}

// ����List�Ĺ���
void TestList1()
{
	fxl::List<int> l1;
	fxl::List<int> l2(10, 5);
	PrintList(l2);

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	fxl::List<int> l3(array, array + sizeof(array) / sizeof(array[0]));


	PrintList(l3);

	fxl::List<int> l4(l3);
	PrintList(l4);

	l1 = l4;
	PrintList(l1);
//	PrintListReverse(l1);
}

// PushBack()/PopBack()/PushFront()/PopFront()
void TestList2()
{
	// ����PushBack��PopBack
	fxl::List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	PrintList(l);

	l.PopBack();
	l.PopBack();
	PrintList(l);

	l.PopBack();
	cout << l.Size() << endl;

	// ����PushFront��PopFront
	l.PushFront(1);
	l.PushFront(2);
	l.PushFront(3);
	PrintList(l);

	l.PopFront();
	l.PopFront();
	PrintList(l);

	l.PopFront();
	cout << l.Size() << endl;
}

void TestList3()
{
	int array[] = { 1, 2, 3, 4, 5 };
	fxl::List<int> l(array, array + sizeof(array) / sizeof(array[0]));

	auto pos = l.Begin();
	l.Insert(l.Begin(), 0);
	PrintList(l);

	++pos;
	l.Insert(pos, 2);

	PrintList(l);
	l.Erase(l.Begin());
	l.Erase(pos);
	PrintList(l);

	// posָ��Ľڵ��Ѿ���ɾ����pos������ʧЧ
	cout << *pos << endl;

	auto it = l.Begin();
	while (it != l.End())
	{
		it = l.Erase(it);
	}
	cout << l.Size() << endl;
}

// ReSize/Clear/Swap
void TestList4()
{
	int array[] = { 1, 2, 3, 4, 5 };
	fxl::List<int> l1(array, array + sizeof(array) / sizeof(array[0]));
	cout << l1.Size() << endl;
	PrintList(l1);

	l1.ReSize(10, 6);
	cout << l1.Size() << endl;
	PrintList(l1);

	l1.ReSize(4);
	cout << l1.Size() << endl;
	PrintList(l1);

	fxl::List<int> l2(array, array + sizeof(array) / sizeof(array[0]));
	PrintList(l1);
	PrintList(l2);

	l1.Swap(l2);
	PrintList(l1);
	PrintList(l2);

	l2.Clear();
	cout << l2.Size() << endl;
}

int main(){
	TestList1();
	TestList2();
	TestList3();
	TestList4();
	system("pause");
	return 0;
}