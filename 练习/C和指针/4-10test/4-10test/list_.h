#include<iostream>
using namespace std;
namespace fxl{
	template<class T>
	class ListNode{
		ListNode(const T&val = T())
		:_pNext(nullptr)
		,_pPre(nullptr)
		,_val(val)
		{}

		ListNode<T>* _pNext;
		ListNode<T>* _pPre;
		T _val;
	};
	template<class T,class Ref,class Ptr>
	class ListIterator{
		typedef ListNode<T>* PNode;
		typedef ListIterator<T, Ref, Ptr> Self;
	public:
		ListIterator(PNode pNode=nullptr)
			:_pNode(pNode)
		{}
		
		ListIterator(const Self& l)
		:_pNode(l._pNode)
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
			return _pNode == l._pNode;
		}
	private:
		PNode _pNode;
	};

		template<class T, class Ref, class Ptr, class Iterator>
		class ListReverseIterator
		{
			typedef ListReverseIterator<T, Ref, Ptr, Iterator> Self;
		public:
			ListReverseIterator(const Iterator& it)
				: _it(it)
			{}
			ListReverseIterator(const Self& s)
				: _it(s._it)
			{}
			Ref operator*()
			{
				Iterator temp = _it;
				return *(--temp);
			}
			Ptr operator->()
			{
				return &operator*();
			}
			// 反向迭代器的++，就是正向迭代器的--
			Self& operator++()
			{
				--_it;
				return *this;
			}
			Self operator++(int)
			{
				Iterator temp(_it);
				--_it;
				return temp;
			}
			// 反向迭代器的--，就是正向迭代器的++
			Self& operator--()
			{
				++_it;
				return *this;
			}
			Self operator--(int)
			{
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
	class List
	{
		typedef ListNode<T> Node;
		typedef Node* PNode;
	public:
		typedef ListIterator<T, T&, T*> Iterator;
		typedef ListIterator<T, const T&, const T*> ConstIterator;
		typedef ListReverseIterator<T, T&, T*, Iterator> ReverseIterator;
		typedef ListReverseIterator<T, const T&, const T*, ConstIterator> ConstReverseIterator;
	public:
		List()
		{
			CreateHead();
		}

		List(size_t n, const T& value = T())
		{
			CreateHead();
			for (size_t i = 0; i < n; i++)
				PushBack(value);

		}

		template<class Iterator>
		List(Iterator start, Iterator last)
		{
			CreateHead();
			while (start != last)
			{
				PushBack(*start);
				start++;
			}
		}

		List(const List<T>& l)
		{
			CreateHead();
			// 用l中的元素构造临时的temp,然后与当前对象交换
			List<T> temp(l.CBegin(), l.CEnd());
			this->Swap(temp);
		}

		List<T>& operator=(const List<T>& l)
		{
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

		/////////////list iterator
		Iterator Begin(){
			return Iterator(_pHead->_pNext);
		}

		Iterator End(){
			return Iterator(_pHead);
		}

		ReverseIterator RBegin(){
			return ReverseIterator(End());
		}

		ReverseIterator REnd(){
			return ReverseIterator(Begin());
		}

		ConstIterator CBegin()const{
			return ConstIterator(_pHead->_pNext);
		}

		ConstIterator CEnd()const{
			return ConstIterator(_pHead);
		}

		ConstReverseIterator CRBegin()const{
			return ConstReverseIterator(CEnd());
		}

		ConstReverseIterator CREnd()const{
			return ConstReverseIterator(CBegin());
		}
		////////////list capacity
		size_t Size()const{
			size_t count = 0;
			PNode pCur = _pHead->_pNode;
			while (pCur != _pHead)
			{
				count++;
				pCur = pCur->_pNext;
			}
			return count;
		}

		bool Empty()const{
			return _pHead->_pNext == _pHead;
		}

		void ReSize(size_t NewSize,const T& val=T()){
			size_t oldsize = Size();
			if (oldsize < NewSize){
				for (size_t i = oldsize; i < NewSize; i++)
					PushBack(val);
			}
			else
			{
				for (size_t i = newSize; i < oldSize; ++i)
					PopBack();
			}
		}
		////////list Access
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
		///list Motidy
		//尾插
		void PushBack(const T& val){
			PNode newNode = new Node(val);
			newNode->_pNext = _pHead;
			newNode->_pPre = _pHead->_pPre;
			_pHead->_pPre->_pNext = newNode;
			_pHead->_pPre = newNode;
		}
		//尾删
		void Pop()
		{
			PNode pDel = _pHead->_pPre;
			if (pDel != _pHead){
				_pHead->_pPre = pDel->_pPre;
				pDel->_pPre->_pNext = _pHead;
				delete pDel;
			}
		}
		//头插
		void PushFront(const T& val){
			PNode newNode = new PNode(val);
			if (newNode != _pHead)
			{
				_pHead->_pNext->_pPre = _pHead;
				newNode->_pNext = _pHead->_pNext;
				_pHead->_pNext = newNode;
				newNode->_pPre = _pHead;
			}
		}
		//头删
		void PopFront(){
			PNode pDel = _pHead->_pNext;
			if (pDel != _pHead)
			{
				_pHead->_pNext = pDel->_pNext;
				pDel->_pNext->_pPre = _pHead;
				delete pDel;
			}
		}
		
		Iterator Insert(Iterator pos, const T& val){
			PNode newNode = new PNode(val);
			PNode pCur = pos._pNode;

			newNode->_pPre = pCur;
			newNode->_pNext = pCur->_pNext;
			pCur->_pNext = newNode;
			newNode->_pNext->_pPre = newNode;
			return Iterator(newNode);
		}
		Iterator Erase(Iterator pos){
			PNode popNode = pos._pNode;
			PNode revNode = popNode->_pNext;

			popNode->_pPre->_pNext = popNode->_pNext;
			popNode->_pNext = popNode->_pPre;
			delete popNode;
			return Iterator(revNode);
		}

		void Clear(){
			PNode pDel = _pHead->_pNext;
			while (pDel != _pHead)
			{
				_pHead->_pNext = pDel->_pNext;
				delete pDel;
				pDel = _pHead->_pNext;
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