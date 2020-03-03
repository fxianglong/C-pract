#include<iostream>
#include<assert.h>
using namespace std;
namespace fxl
{
	class MyString{
	public:
		typedef char* Iterator;
	public:
		MyString(const char* str="")
		{
			if (nullptr == str)
			{
				assert(str);
				return;
			}
			_str = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		MyString(const MyString& s)
			:_str(new char[_capacity + 1])
			, _capacity(s._size)
			, _size(s._capacity)
		{
			strcpy(_str, s._str);
		}

		MyString& operator=(const MyString& s)
		{
			if (this != &s)
			{
				char* Ptr = new char[s._capacity + 1];
				strcpy(Ptr, s._str);

				delete _str;
				_str = Ptr;
				_capacity = s._capacity;
				_size = s._size;
			}
			return *this;
		}

		~MyString()
		{
			if (_str)
			{
				delete _str;
				_str = nullptr;
			}
		}

		Iterator Begin()
		{
			return _str;
		}

		Iterator End()
		{
			return _str + _size;
		}

		void Push_Back(char c)
		{
			if (_size == _capacity)
			{
				Reserve(_capacity = 2 * _capacity);
			}
			_str[_size++] = c;
			_str[_size] = '\0';
		}

		void Append(size_t n, char c)
		{
			for (size_t i = 0; i < n; i++);
			Push_Back(c);
		}

		MyString& operator+=(char s)
		{
			Push_Back(s);
			return *this;
		}

		void Append(const char* str){
			while (*str)
			{
				Push_Back(*str);
				str++;
			}
		}
		MyString& operator+=(const char* str)
		{
			while (*str){
				Push_Back(*str);
				str++;
			}
		}

		void Clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		void Swap(MyString& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		const char* C_Str()const
		{
			return _str;
		}

		size_t Size()const
		{
			return _size;
		}

		size_t Capacity()const
		{
			return _capacity;
		}

		bool Empty()const
		{
			return 0 == _size;
		}

		void Resize(size_t newSize, char c = char())
		{
			if (newSize > _size)
			{
				if (newSize > _capacity)
					Reserve(newSize);
				memset(_str + _size, c, newSize - _size);
			}
			_size = newSize;
			_str[_size] = '\0';
		}

		void Reserve(size_t newCapacity)
		{
			if (newCapacity > _capacity)
			{
				char* str = new char[newCapacity+1];
				strcpy(str, _str);
				delete _str;
				_str = str;
				_capacity = newCapacity;
			}
		}

		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}

		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}

		bool operator<(const MyString& s)
		{
			int i = 0;
			for (i = 0; i<_size&&i<s._size; i++)
			{
				if (*_str<s[i])
					return false;
				if (*_str>s[i])
					return true;
			}
			if (i == _size)
				return false;
			else return true;
		}
		bool operator<=(const MyString& s)
		{
			int i = 0;
			for (i = 0; i<_size&&i<s._size; i++)
			{
				if (*_str>s[i])
					return false;
				if (*_str<s[i])
					return true;
			}
			if (i == _size)
				return true;
			else return false;
		}
		bool operator>(const MyString& s)
		{
			int i = 0;
			for (i = 0; i<_size&&i<s._size; i++)
			{
				if (*_str<s[i])
					return false;
				if (*_str>=s[i])
					return true;
			}
			if (i == _size)
				return false;
			else return true;
		}
		bool operator>=(const MyString& s)
		{
			int i = 0;
			for (i = 0; i<_size&&i<s._size; i++)
			{
				if (*_str>=s[i])
					return false;
				if (*_str<s[i])
					return true;
			}
			if (i == _size)
				return true;
			else return false;
		}
		bool operator==(const MyString& s)
		{
			int i = 0;
			for (i = 0; i < _size&&i < s._size; i++)
			{
				if (_str[i] != s[i])
					return false;
			}
			if (i == _size&&i == s._size)
				return true;
			else
			{
				return false;
			}
		}
		bool operator!=(const MyString& s)
		{
			int i = 0;
			for (i = 0; i < _size&&i < s._size; i++)
			{
				if (_str[i] == s[i])
					return false;
			}
			if (i == _size&&i == s._size)
				return false;
			else
			{
				return true;
			}
		}

	private:
		friend ostream& operator<<(ostream& _cout, const fxl::MyString& s);
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}