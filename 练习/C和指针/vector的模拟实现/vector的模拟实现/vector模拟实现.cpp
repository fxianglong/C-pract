#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
namespace fxl
{
	template<class T>
	class vector
	{
	public:
		typedef T* Iterator;
		typedef const T* ConstIterator;
		Iterator Begin(){ return _start; }
		Iterator End(){ return _finish; }

		ConstIterator CBegin(){ return _start; }
		ConstIterator CEnd(){ return _finish; }

		size_t Size(){ return _finish - _start; }
		size_t Capacity(){ return _endOfStorage - _start; }

		vector()
		:_start=nullptr
		,_finish=nullptr
		,_endOfStorage=nullptr
		{}

		vector(int n, const T& value = T())
		:_start=nullptr
		,_finish=nullptr
		,_endOfStorage=nullptr
		{
			Reserve(n);
			while (n--)
			{
				Push_Back(value);
			}
		}

		template<class InputIterator>
		Vector(InputIterator first, InputIterator last)
		{
			Reserve(last - first);
			while (first!=last)
			{
				Push_Back(*first);
				first++:
			}
		}

		vector(const vector<T>& v)
			:_start=nullptr
			,_finish=nullptr
			,_endOfStorage=nullptr
		{
			Reserve(v.Capacity());
			Iterator it = Begin();
			const vit = v.CBegin();
			while (vit != v.CEnd())
			{
				*it++ = *vit++;
			}
			_finish = _start + v.Size();
			_endOfStorage = _start + v.Capacity();
		}

		vector<T>& operator= (vector<T> v)
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}

		void Reserve(size_t n)
		{
			if (n > Capacity())
			{
				size_t size = Size();
				T tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < size; ++i)
						tmp[i] = _start[i];
				}
				_start = tmp;
				_finish = _start + size;
				_endOfStorage = _start + n;
			}
		}

		void Resize(size_t n, const T& value = T())
		{
			if (n < Capacity())
			{
				_finish = _start + n;
				return;
			}
			else
			{
				Reserve(n);
			}
			Iterator it = _finish;
			Iterator _finish = _start + n;
			while (it != _finish)
			{
				*it++ = value;
			}
		}

		void Swap(Vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endOfStorage, v._endOfStorage);
		}

		void PushBack(const T& x)
		{
			Insert(End(), x);
		}

		void PopBack()
		{
			Erase(--End());
		}

		Iterator Insert(Iterator pos, const T& x)
		{
			assert(pos <= _finish);
			//如果空间不足就增容
			if (_finish == _endOfStorage)
			{
				size_t size = Size();
				size_t newCapacity = Capacity == 0 ? 1 : Capacity() * 2;
				Reserve(newCapacity);
				//如果发生增容，需要重置pos
				pos = _start + size;
			}
			Iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		Iterator Erase(Iterator pos)
		{
			// 挪动数据进行删除
			Iterator begin = pos + 1;
			while (begin != _finish) {
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			return pos;
		}

		T& operator[](size_t pos)
		{
			return _start[pos];
		}
	private:
		Iterator _start;        // 指向数据块的开始
		Iterator _finish;       // 指向有效数据的尾
		Iterator _endOfStorage;
	};
}

