#include<iostream>
#include<vector>
#include<mutex>
#include<map>
#include<string>
using namespace std;
//int main()
//{
//	// �������ͱ���
//	int x1 = { 10 };
//	int x2{ 10 };
//	int x3 = 1 + 2;
//	int x4 = { 1 + 2 };
//	int x5{ 1 + 2 };
//	// ����
//	int arr1[5] {1, 2, 3, 4, 5};
//	int arr2[]{1., 2, 3, 4, 5};
//
//	// ��̬���飬��C++98�в�֧��
//	int* arr3 = new int[5]{1, 2, 3, 4, 5};
//
//	// ��׼����
//	vector<int> v{ 1, 2, 3, 4, 5 };
//	map<int, int> m{ { 1, 1 }, { 2, 2, }, { 3, 3 }, { 4, 4 } };
//	return 0;
//}

//class Point
//{
//public:
//	Point(int x = 0, int y = 0) : _x(x), _y(y)
//	{}
//private:
//	int _x;
//	int _y;
//};
//
//int main()
//{
//	Point p{ 1, 2 };
//	return 0;
//}


//#include <initializer_list>
//template<class T>
//class Vector {
//public:
//	// ...    
//	Vector(initializer_list<T> l) : _capacity(l.size()), _size(0)
//	{
//		_array = new T[_capacity];
//		for (auto e : l)
//			_array[_size++] = e;
//	}
//
//	Vector<T>& operator=(initializer_list<T> l) {
//		delete[] _array;
//		size_t i = 0;
//		for (auto e : l)
//			_array[i++] = e;
//		return *this;
//	}
//	// ...
//private:
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};


//#include <map>
//#include <string>
//int main()
//{
//	short a = 32670;
//	short b = 32670;
//
//	// c�������short����������ݶ�ʧ������ܹ��ñ���������a+b�Ľ���Ƶ�c��ʵ�����ͣ��Ͳ����������
//	short c = a + b;
//	auto d = a + b;
//	std::map<std::string, std::string> m{ { "apple", "ƻ��" }, { "banana", "�㽶" } };
//	// ʹ�õ�������������, ����������̫����
//	std::map<std::string, std::string>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		cout << it->first << " " << it->second << endl;
//		++it;
//	}
//	auto its = m.begin();
//	while (its != m.end())
//	{
//		cout << its->first << " " << its->second << endl;
//		++its;
//	}
//	return 0;
//}


//int main()
//{
//	double a = 10.9887;
//	int b = 20;
//
//	// ��decltype����a+b��ʵ�����ͣ���Ϊ����c������
//	decltype(a + b) c;
//	c = a + b;
//	cout << typeid(c).name() << endl;
//	cout << c << endl;
//
//	return 0;
//}

//void* GetMemory(size_t size)
//{
//	return malloc(size);
//}
//
//int main()
//{
//	// ���û�д��������Ƶ�����������
//	cout << typeid(decltype(GetMemory)).name() << endl;
//
//	// ����������б��Ƶ����Ǻ�������ֵ������,ע�⣺�˴�ֻ�����ݣ�����ִ�к���
//	cout << typeid(decltype(GetMemory(0))).name() << endl;
//
//	return 0;
//}


//class A
//{
//public:
//	A(int a) : _a(a)
//	{}
//	// ��ʽȱʡ���캯�����ɱ���������
//	A() = default;
//
//	// �����������������ⶨ��ʱ�ñ���������Ĭ�ϸ�ֵ���������
//	A& operator=(const A& a);
//private:
//	int _a;
//};
//
//A& A::operator=(const A& a) = default;
//int main()
//{
//	A a1(10);
//	A a2;
//	a2 = a1;
//	return 0;
//}


//class A
//{
//public:
//	A(int a) : _a(a)
//	{}
//
//	// ��ֹ����������Ĭ�ϵĿ������캯���Լ���ֵ���������
//	A(const A&) = delete;
//	A& operator=(const A&) = delete;
//private:
//	int _a;
//};
//
//int main()
//{
//	A a1(10);
//	// ����ʧ�ܣ���Ϊ����û�п������캯��
//		//A a2(a1);
//	// ����ʧ�ܣ���Ϊ����û�и�ֵ���������
//	A a3(20);
//		//a3 = a2;
//	return 0;
//}


//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	const int&& ra = 10;
//	auto v = &ra;
//	// ���ú�������ֵ������ֵ��һ����ʱ������Ϊ��ֵ
//	int&& rRet = Add(10, 20);
//	return 0;
//}


//class String
//{
//public:
//	String(char* str = "")
//	{
//		if (nullptr == str)
//			str = "";
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
//	String(const String& s)
//		: _str(new char[strlen(s._str) + 1])
//	{
//		strcpy(_str, s._str);
//	}
//	String& operator=(const String& s)
//	{
//		if (this != &s)
//		{
//			char* pTemp = new char[strlen(s._str) + 1];
//			strcpy(pTemp, s._str);
//			delete[] _str;
//			_str = pTemp;
//		}
//		return *this;
//	}
//
//	String operator+(const String& s)
//	{
//		char* pTemp = new char[strlen(_str) + strlen(s._str) + 1];
//		strcpy(pTemp, _str);
//		strcpy(pTemp + strlen(_str), s._str);
//		String strRet(pTemp);
//		return strRet;
//	}
//
//	~String()
//	{
//		if (_str) delete[] _str;
//	}
//private:
//	char* _str;
//};
//
//int main()
//{
//	String s1("hello");
//	String s2("world");
//	String s3(s1 + s2);
//	return 0;
//}



//class Person
//{
//public:
//	Person(char* name, char* sex, int age)
//		: _name(name)
//		, _sex(sex)
//		, _age(age)
//	{}
//
//	Person(const Person& p)
//		: _name(p._name)
//		, _sex(p._sex)
//		, _age(p._age)
//	{}
//
//#if 0
//
//	Person(Person&& p)
//		: _name(p._name)
//		, _sex(p._sex)
//		, _age(p._age)
//	{}
//
//#else
//	Person(Person&& p)
//		: _name(move(p._name))
//		, _sex(move(p._sex))
//		, _age(p._age)
//	{}
//
//#endif
//
//private:
//	string _name;
//	string _sex;
//	int _age;
//};
//
//Person GetTempPerson()
//{
//	Person p("prety", "male", 18);
//	return p;
//}
//
//int main()
//{
//	Person p(GetTempPerson());
//	return 0;
//}



//void Fun(int &x){ cout << "lvalue ref" << endl; }
//void Fun(int &&x){ cout << "rvalue ref" << endl; }
//void Fun(const int &x){ cout << "const lvalue ref" << endl; }
//void Fun(const int &&x){ cout << "const rvalue ref" << endl; }
//
//template<typename T>
//void PerfectForward(T &&t){ Fun(std::forward<T>(t)); }
//
//int main()
//{
//	PerfectForward(10); // rvalue ref
//
//	int a;
//	PerfectForward(a); // lvalue ref
//	PerfectForward(std::move(a)); // rvalue ref
//
//	const int b = 8;
//	PerfectForward(b); // const lvalue ref
//	PerfectForward(std::move(b)); // const rvalue ref
//
//	return 0;
//}


//int main()
//{
//	// ��򵥵�lambda���ʽ, ��lambda���ʽû���κ�����
//	[]{};
//
//	// ʡ�Բ����б�ͷ���ֵ���ͣ�����ֵ�����ɱ������Ƶ�Ϊint
//	int a = 3, b = 4;
//	[=]{return a + 3; };
//
//	// ʡ���˷���ֵ���ͣ��޷���ֵ����
//	auto fun1 = [&](int c){b = a + c; };
//	fun1(10);
//		cout << a << " " << b << endl;
//
//	// �����ֶ������Ƶ�lambda����
//	auto fun2 = [=, &b](int c)->int{return b += a + c; };
//	cout << fun2(10) << endl;
//
//	// ���Ʋ�׽x
//
//	int x = 10;
//	auto add_x = [x](int a) mutable { x *= 2; return a + x; };
//	cout << add_x(10) << endl;
//
//	return 0;
//}


//void(*PF)();
//int main()
//{
//	auto f1 = []{cout << "hello world" << endl; };
//	auto f2 = []{cout << "hello world" << endl; };
//
//	// �˴��Ȳ�����ԭ�򣬵�lambda���ʽ�ײ�ʵ��ԭ����󣬴�Ҿ������
//	//f1 = f2;    // ����ʧ��--->��ʾ�Ҳ���operator=()
//	// ����ʹ��һ��lambda���ʽ��������һ���µĸ���
//	auto f3(f2);
//	f3();
//
//	// ���Խ�lambda���ʽ��ֵ����ͬ���͵ĺ���ָ��
//	PF = f2;
//	PF();
//	return 0;
//}


//class Rate
//{
//public:
//	Rate(double rate) : _rate(rate)
//	{}
//
//	double operator()(double money, int year)
//	{
//		return money * _rate * year;
//	}
//
//private:
//	double _rate;
//};
//
//int main()
//{
//	// ��������
//	double rate = 0.49;
//	Rate r1(rate);
//	r1(10000, 2);
//
//	// lamber
//	auto r2 = [=](double monty, int year)->double{return monty*rate*year; };
//	r2(10000, 2);
//	return 0;
//}


#include <thread>
//int main()
//{
//	std::thread t1;
//	cout << t1.get_id() << endl;
//	system("pause");
//	return 0;
//}



//void ThreadFunc(int a)
//{
//	cout << "Thread1" << a << endl;
//}
//
//class TF
//{
//public:
//	void operator()()
//	{
//		cout << "Thread3" << endl;
//	}
//};
//
//int main()
//{
//	// �̺߳���Ϊ����ָ��
//	thread t1(ThreadFunc, 10);
//
//	// �̺߳���Ϊlambda���ʽ
//	thread t2([](const int x){cout << "Thread2" << x<<endl; },3);
//
//	// �̺߳���Ϊ��������
//	TF tf;
//	thread t3(tf);
//
//	t1.join();
//	t2.join();
//	t3.join();
//	cout << "Main thread!" << endl;
//	return 0;
//}



//void ThreadFunc1(int& x)
//{
//	x += 10;
//}
//
//void ThreadFunc2(int* x)
//{
//	*x += 10;
//}
//
//int main()
//{
//	int a = 10;
//
//	// ���̺߳����ж�a�޸ģ�����Ӱ���ⲿʵ�Σ���Ϊ���̺߳���������Ȼ�����÷�ʽ������ʵ�����õ����߳�ջ�еĿ���
//	thread t1(ThreadFunc1, a);
//	t1.join();
//	cout << a << endl;
//
//	// �����Ҫͨ���βθı��ⲿʵ��ʱ���������std::ref()����
//	thread t2(ThreadFunc1, std::ref(a));
//	t2.join();
//	cout << a << endl;
//
//	// ��ַ�Ŀ���
//	thread t3(ThreadFunc2, &a);
//	t3.join();
//	cout << a << endl;
//	system("pause");
//	return 0;
//}


//// jion()������һ
//void ThreadFunc() { cout << "ThreadFunc()" << endl; }
//bool DoSomething() { return false; }
//int main()
//{
//	std::thread t(ThreadFunc);
//	if (bool ret = !DoSomething())
//		return -1;
//
//	t.join();
//	return 0;
//}
/*
˵�������DoSomething()��������false,���߳̽��������jion()û�е��ã��߳���Դû�л��գ�
�����Դй©��
*/

//// jion()�����ö�
//void ThreadFunc() { cout << "ThreadFunc()" << endl; }
//void Test1() { throw 1; }
//void Test2()
//{
//	int* p = new int[10];
//	std::thread t(ThreadFunc);
//	try
//	{
//		Test1();
//	}
//	catch (...)
//	{
//		delete[] p;
//		throw;
//	}
//
//	t.jion();
//}


//class mythread
//{
//public:
//	explicit mythread(std::thread &t) :m_t(t){}
//	~mythread()
//	{
//		if (m_t.joinable())
//			m_t.join();
//	}
//
//	mythread(mythread const&) = delete;
//	mythread& operator=(const mythread &) = delete;
//
//private:
//	std::thread &m_t;
//};
//
//void ThreadFunc() { cout << "ThreadFunc()" << endl; }
//bool DoSomething() { return false; }
//
//int main()
//{
//	thread t(ThreadFunc);
//	mythread q(t);
//
//	if (DoSomething())
//		return -1;
//
//	return 0;
//}



//unsigned long sum = 0L;
//
//void fun(size_t num)
//{
//	for (size_t i = 0; i < num; ++i)
//		sum++;
//}
//
//int main()
//{
//	cout << "Before joining,sum = " << sum << std::endl;
//
//	thread t1(fun, 10000000);
//	thread t2(fun, 10000000);
//	t1.join();
//	t2.join();
//
//	cout << "After joining,sum = " << sum << std::endl;
//	return 0;
//}



//std::mutex m;
//unsigned long sum = 0L;
//
//void fun(size_t num)
//{
//	for (size_t i = 0; i < num; ++i)
//	{
//		m.lock();
//		sum++;
//		m.unlock();
//	}
//}
//
//int main()
//{
//	cout << "Before joining,sum = " << sum << std::endl;
//
//	thread t1(fun, 10000000);
//	thread t2(fun, 10000000);
//	t1.join();
//	t2.join();
//
//	cout << "After joining,sum = " << sum << std::endl;
//	return 0;
//}

#include <atomic>

atomic_long sum{ 0 };

void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
		sum++;   // ԭ�Ӳ���
}

int main()
{
	cout << "Before joining, sum = " << sum << std::endl;

	thread t1(fun, 1000000);
	thread t2(fun, 1000000);
	t1.join();
	t2.join();

	cout << "After joining, sum = " << sum << std::endl;
	return 0;
}