//#include<iostream>
//#include<deque>
//using namespace std;
//void PrintDeque(const std::deque<int>& d){
//	for (auto n : d){
//		cout << n << " ";
//	}
//	cout << endl;
//}
////����deque�Ĺ��캯��
//void TestDeque1(){
//	std::deque<int> d1;
//	PrintDeque(d1);
//	std::deque<int> d2(5, 10);
//	PrintDeque(d2);
//	std::deque<int> d3(d2.begin(), d2.end());
//	PrintDeque(d3);
//	int array[] = { 3, 24, 35, 46, 3, 7, 54, 32, 23, 345, 6, 7, 6554, 23 };
//	std::deque<int> d5(array, array+sizeof(array) / sizeof(array[0]));
//	PrintDeque(d5);
//	std::deque<int> d4(d5);
//	PrintDeque(d4);
//}
//
////����deque�ĵ�����
//void TestDeque2(){
//	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	std::deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
//
//	// ���������������ӡdeque�е�Ԫ��
//	for (auto it = d.cbegin(); it != d.cend(); ++it)
//		cout << *it << " ";
//	cout << endl;
//
//	auto cit = d.cbegin();
//	//*it = 100;   ����������ʧ�ܣ�itΪconst����������ָ��ռ�Ԫ��ֵ�����޸�
//
//
//	// ���÷�������������ӡdeque�е�Ԫ��
//	for (auto it = d.crbegin(); it != d.crend(); ++it)
//		cout << *it << " ";
//	cout << endl;
//}
//
//void TestDeque3()
//{
//	// �б�ʽ��ʼ����C++11�﷨
//	deque<int> d1{ 3, 4, 5 };
//
//	// ��deque��β������5��ͷ������1������ӡ
//	d1.push_back(6);
//	d1.push_front(2);
//	PrintDeque(d1);
//	cout << d1.size() << endl;
//	cout << d1.front() << endl;
//	cout << d1.back() << endl;
//
//	// ��deque��β������6��ͷ������0
//	// ע�⣺�������������Ԫ�أ�
//	//      emplace_back��push_back emplace_front��push_front��Ч����ͬ
//	//      ������Զ�������Ԫ��
//	//      emplace_back/emplace_front��Ч�ʸ��ߣ�����������ֱ����β������ͷ������Ԫ��
//	//      push_back/push_front��Ч�ʵͣ��ò���ʱ�Ƚ�Ԫ�ع���ã�Ȼ�󿽱���β����ͷ��
//	d1.emplace_back(7);
//	d1.emplace_front(1);
//	PrintDeque(d1);
//
//	// ��deque��beginλ�ò���Ԫ��0
//	d1.insert(d1.begin(), 0);
//	PrintDeque(d1);
//
//	// ɾ��deque�ײ���β��Ԫ��
//	d1.pop_front();
//	d1.pop_back();
//	d1.erase(d1.begin());
//	PrintDeque(d1);
//
//	// ��deque�е�Ԫ�����
//	d1.clear();
//	cout << d1.size() << endl;
//}
//int main()
//{
//	//TestDeque1();
//	//TestDeque2();
//	TestDeque3();
//	system("pause");
//	return 0;
//}
//
//// ���⣺���Ҫ��deque�е�Ԫ�ؽ����������µ�Ч�ʸ���
//#include <algorithm>
//#include <deque>
//void TestDequeSort()
//{
//	int array[] = { 5, 2, 1, 9, 6, 3, 8, 7, 4, 0 };
//	deque<int> d(array, array + sizeof(array) / sizeof(array[0]));
//	PrintDeque(d);
//
//	// ���ñ�׼���е��㷨��deque�е�Ԫ�ؽ�����������
//	sort(d.begin(), d.end());
//	PrintDeque(d);
//}
//
///*
//������deque�����������Ч���Ƿǳ��͵ģ�����deque����ʱ����Ҫ��ζ�deque�е�Ԫ�ؽ��������������
//deque�е�Ԫ���������ʱЧ�ʱȽϵͣ�������Ϊdeque�ײ�Ŀռ䲻���������Ҫ���������������ĳ�οռ��
//Ĭ�ϻ��ײ�ʱ������Ҫ������һ�λ���ǰһ�οռ��λ�ã�����deque��Ч�ʱȽϵ��¡�
//*/


//#include<iostream>
//#include<deque>
//using namespace std;
//template<class T,class Con=deque<T>>
//class Stack
//{
//public:
//	Stack(){}
//	void Push(const T& x){ _c.push_back(x); }
//	void Pop(){ _c.pop_back(); }
//	T& Top(){ return _c.back(); }
//	const T& Top()const{ return _c.back(); }
//	size_t Size()const{ return _c.size(); }
//	bool Empty()const{ return _c.empty(); }
//private:
//	Con _c;
//};
//void TestStack()
//{
//	Stack<int> s;
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//	cout << s.Size() << endl;
//	cout << s.Top() << endl;
//	s.Pop();
//	s.Pop();
//	cout << s.Size() << endl;
//	cout << s.Top() << endl;
//	system("pause");
//}
//int main()
//{
//	TestStack();
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<deque>
//using namespace std;
//template<class T, class Con = deque<T>>
//class Queue
//{
//public:
//	Queue(){}
//	void Push(const T& x){ _c.push_back(x); }
//	void Pop(){ _c.pop_front(); }
//	T& Back(){ return _c.back(); }
//	const T& Back()const{ return _c.back(); }
//	T& Front(){ return _c.front(); }
//	const T& Front()const{ return _c.front(); }
//	size_t Size()const{ return _c.size(); }
//	bool Empty()const{ return _c.empty(); }
//private:
//	Con _c;
//};
//void TestQueue()
//{
//	// ���������ڵڶ���ģ���������ʹ�ò�ͬ��������Ȼ���������ɵ�queueЧ����һ���ġ�
//	//Queue<int, deque<int>> q;
//	//Queue<int, list<int>> q;
//
//	Queue<int> q;
//	q.Push(1);
//	q.Push(2);
//	q.Push(3);
//	q.Push(4);
//	cout << q.Size() << endl;
//	cout << q.Front() << endl;
//	cout << q.Back() << endl;
//
//	q.Pop();
//	q.Pop();
//	cout << q.Size() << endl;
//	cout << q.Front() << endl;
//	cout << q.Back() << endl;
//}
//int main()
//{
//	TestQueue();
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;
//template<class T>
//bool IsEqual(T& left, T& right)
//{
//	return left == right;
//}
//
//void Test()
//{
//	char* p1 = "hello";
//	char* p2 = "hello1";
//
//	if (IsEqual(p1, p2))
//		cout << p1 << endl;
//	else
//		cout << p2 << endl;
//}


template<class T>
void Copy(T dst, const T src, size_t size)
{
	memcpy(dst, src, sizeof(T)*size);
}

int main()
{
	// ��������Ĵ���
	string strarr1[3] = { "11", "22", "33" };
	string strarr2[3];
	Copy(strarr2, strarr1, 3);
	system("pause");
	return 0;
}
//int main(){
//	Test();
//	system("pause");
//	return 0;
//}