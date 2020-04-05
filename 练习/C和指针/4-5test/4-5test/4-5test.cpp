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
//	std::list<int> l1;                         // 构造空的l1
//	std::list<int> l2(4, 100);                 // l2中放4个值为100的元素
//	std::list<int> l3(l2.begin(), l2.end());  // 用l2的[begin(), end()）左闭右开的区间构造l3
//	std::list<int> l4(l3);                    // 用l3拷贝构造l4
//
//	// 以数组为迭代器区间构造l5
//	int array[] = { 16, 2, 77, 29 };
//	std::list<int> l5(array, array + sizeof(array) / sizeof(int));
//
//	// 用迭代器方式打印l5中的元素
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
//	// 将list中第一个节点与最后一个节点中的值改为10
//	l1.front() = 10;
//	l1.back() = 10;
//
//	for (auto& e : l1)
//		cout << e << " ";
//	cout << endl;
//
//	const list<int> l2(array, array + sizeof(array) / sizeof(array[0]));
//	//int& a = l2.front();//   因为l2是const类型的list对象，因此其front()为const 引用类型
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
//	// 在list的尾部插入4，头部插入0
//	L.push_back(4);
//	L.push_front(0);
//	PrintList(L);
//
//	// 删除list尾部节点和头部节点
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
//// push_back尾插：先构造好元素，然后将元素拷贝到节点中，插入时先调构造函数，再调拷贝构造函数
//// emplace_back尾插：先构造节点，然后调用构造函数在节点中直接构造对象
//// emplace_back比push_back更高效，少了一次拷贝构造函数的调用
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
//	// 获取链表中第二个节点
//	auto pos = ++L.begin();
//	cout << *pos << endl;
//
//	// 在pos前插入值为4的元素
//	L.insert(pos, 4);
//	PrintList(L);
//
//	// 在pos前插入5个值为5的元素
//	L.insert(pos, 5, 5);
//	PrintList(L);
//
//	// 在pos前插入[v.begin(), v.end)区间中的元素
//	vector<int> v{ 7, 8, 9 };
//	L.insert(pos, v.begin(), v.end());
//	PrintList(L);
//
//	// 删除pos位置上的元素
//	L.erase(pos);
//	PrintList(L);
//
//	// 删除list中[begin, end)区间中的元素，即删除list中的所有元素
//	L.erase(L.begin(), L.end());
//	PrintList(L);
//}
//
//// resize/swap/clear
//void TestList4()
//{
//	// 用数组来构造list
//	int array1[] = { 1, 2, 3 };
//	list<int> l1(array1, array1 + sizeof(array1) / sizeof(array1[0]));
//	PrintList(l1);
//
//	// 将l1中元素个数增加到10个，多出的元素用默认值填充
//	// (注意：如果list中放置的是内置类型，默认值为0, 如果list中放置自定义类型元素，调用缺省构造函数)
//		l1.resize(10);
//
//	PrintList(l1);
//	// 将l1中的元素增加到20个，多出的元素用4来填充
//	l1.resize(20, 4);
//	PrintList(l1);
//
//	// 将l1中的元素减少到5个
//	l1.resize(5);
//	PrintList(l1);
//
//	// 用vector中的元素来构造list
//	vector<int> v{ 4, 5, 6 };
//	list<int> l2(v.begin(), v.end());
//	PrintList(l2);
//
//	// 交换l1和l2中的元素
//	l1.swap(l2);
//	PrintList(l1);
//	PrintList(l2);
//
//	// 将l2中的元素清空
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
//		// erase()函数执行后，it所指向的节点已被删除，因此it无效，在下一次使用it时，必须先给其赋值
//			l.erase(it);
//		++it;
//	}
//}
//
//// 改正
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
	// List的节点类
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
	List 的迭代器
	迭代器有两种实现方式：
	1. 原生态指针，比如：vector
	2. 将原生态指针进行封装，因迭代器的使用形式与指针完全相同，因此，在自定义的类中必须实现以下方
	法：
	1. 指针可以解引用，迭代器的类中必须重载operator*()
	2. 指针可以通过->访问其所指空间成员，迭代器类中必须重载oprator->()
	3. 指针可以++向后移动，迭代器类中必须重载operator++()与operator++(int)
	至于operator--()/operator--(int)释放需要重载，根据具体的结构来抉择，双向链表可以向前
	移               动，所以需要重载，如果是forward_list就不需要重载--
	4. 迭代器需要进行是否相等的比较，因此还需要重载operator==()与operator!=()
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
	List 的反向迭代器，反向迭代器与正向迭代器刚好是相反的，反向迭代器++，迭代器往前移动，反向迭代
	器--，     迭代器往后移动，因此反向迭代器可以在正向迭代器的基础之上来实现
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
		// 反向迭代器的++，就是正向迭代器的--
		Self operator++(){
			_it--;
			return *this;
		}
		Self operator++(int){
			Iterator temp(_it);
			--_it;
			return temp;
		}
		// 反向迭代器的--，就是正向迭代器的++
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

			// 先把新节点尾插进去
			pNewNode->_pNext = _pHead;
			pNewNode->_pPre = _pHead->_pPre;
			// 再链接剩余两个指针
			_pHead->_pPre = pNewNode;
			pNewNode->_pPre->_pNext = pNewNode;
		}

		// 尾删
		void PopBack()
		{
			// 找到待删除节点
			PNode pDel = _pHead->_pPre;
			if (pDel != _pHead)
			{
				_pHead->_pPre = pDel->_pPre;
				pDel->_pPre->_pNext = _pHead;
				delete pDel;
			}
		}

		// 头插
		void PushFront(const T& val)
		{
			PNode pNewNode = new Node(val);

			// 先把新节点尾插进去
			pNewNode->_pNext = _pHead->_pNext;
			pNewNode->_pPre = _pHead;
			// 再链接剩余两个指针
			_pHead->_pNext = pNewNode;
			pNewNode->_pNext->_pPre = pNewNode;
		}

		// 头删
		void PopFront()
		{
			// 找到待删除节点

			PNode pDel = _pHead->_pNext;
			if (pDel != _pHead)
			{
				_pHead->_pNext = pDel->_pNext;
				pDel->_pNext->_pPre = _pHead;
				delete pDel;
			}
		}

		// 在pos位置前插入值为val的节点
		Iterator Insert(Iterator pos, const T& val)
		{
			PNode pNewNode = new Node(val);
			PNode pCur = pos._pNode;
			// 先将新节点插入
			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;
			return Iterator(pNewNode);
		}

		// 删除pos位置的节点，返回该节点的下一个位置
		Iterator Erase(Iterator pos)
		{
			// 找到待删除的节点
			PNode pDel = pos._pNode;
			PNode pRet = pDel->_pNext;

			// 将该节点从链表中拆下来并删除
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

// 正向打印链表
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

// 反向打印链表
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

// 测试List的构造
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
	// 测试PushBack与PopBack
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

	// 测试PushFront与PopFront
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

	// pos指向的节点已经被删除，pos迭代器失效
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