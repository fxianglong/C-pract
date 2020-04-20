//#include<iostream>
//#include<pthread.h>
//#include<unistd.h>
//using namespace std;
//const int i = 5;
//__thread int var = i;//两种方式效果一样
////__thread int var=5;//
//void* worker1(void* arg);
//void* worker2(void* arg);
//int main(){
//	pthread_t pid1, pid2;
//	//__thread int temp=5;
//	static __thread  int temp = 10;//修饰函数内的static变量
//	pthread_create(&pid1, NULL, worker1, NULL);
//	pthread_create(&pid2, NULL, worker2, NULL);
//	pthread_join(pid1, NULL);
//	pthread_join(pid2, NULL);
//	cout << temp << endl;//输出10
//	return 0;
//}
//void* worker1(void* arg){
//	cout << ++var << endl;//输出 6
//}
//void* worker2(void* arg){
//	sleep(1);//等待线程1改变var值，验证是否影响线程2
//	cout << ++var << endl;//输出6
//}
//#include<iostream>
//#include<pthread.h>
//#include<unistd.h>
//using namespace std;
//const int i = 5;
//__thread int var = i;
//
//void* worker1(void* arg);
//void* worker2(void* arg);
//int main(){
//	pthread_t pid1, pid2;
//
//	static __thread  int temp = 10;
//	pthread_create(&pid1, NULL, worker1, NULL);
//	pthread_create(&pid2, NULL, worker2, NULL);
//	pthread_join(pid1, NULL);
//	pthread_join(pid2, NULL);
//	cout << temp << endl;
//	return 0;
//}
//void* worker1(void* arg){
//	cout << ++var << endl;
//}
//void* worker2(void* arg){
//	sleep(1);
//	cout << ++var << endl;
//}

//#include<iostream>
//#include <set>
//using namespace std;
//void TestSet()
//{
//	// 用数组array中的元素构造set
//	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0,3,3,3,3,3,3 };
//	set<int> s(array, array + sizeof(array) / sizeof(array[0]));
//	cout << s.size() << endl;
//
//	// 正向打印set中的元素，从打印结果中可以看出：set可去重
//	for (auto& e : s)
//		cout << e << " ";
//	cout << endl;
//
//	// 使用迭代器逆向打印set中的元素
//	for (auto it = s.rbegin(); it != s.rend(); ++it)
//		cout << *it << " ";
//	cout << endl;
//
//	// set中值为3的元素出现了几次
//	cout << s.count(3) << endl;
//	s.insert(11);
//	s.erase(3);
//	set<int>::reverse_iterator rit = s.rbegin();
//	while (rit != s.rend()){
//		cout << *rit<<" ";
//		rit++;
//	}
//}
//int main()
//{
//	TestSet();
//	system("pause");
//	return 0;
//}

#include<iostream>
#include <string>
#include <map>
using namespace std;
void TestMap()
{
	map<string, string> m;

	// 向map中插入元素的方式：
	// 将键值对<"peach","桃子">插入map中，用pair直接来构造键值对
	m.insert(pair<string, string>("peach", "桃子"));

	// 将键值对<"peach","桃子">插入map中，用make_pair函数来构造键值对
	m.insert(make_pair("banan", "香蕉"));

	// 借用operator[]向map中插入元素
	/*
	operator[]的原理是：
	用<key, T()>构造一个键值对，然后调用insert()函数将该键值对插入到map中
	如果key已经存在，插入失败，insert函数返回该key所在位置的迭代器
	如果key不存在，插入成功，insert函数返回新插入元素所在位置的迭代器
	operator[]函数最后将insert返回值键值对中的value返回
	*/
	// 将<"apple", "">插入map中，插入成功，返回value的引用，将“苹果”赋值给该引用结果，
	m["apple"] = "苹果";

	// key不存在时抛异常
	//m.at("waterme") = "水蜜桃";
	cout << m.size() << endl;

	// 用迭代器去遍历map中的元素，可以得到一个按照key排序的序列
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;

	// map中的键值对key一定是唯一的，如果key存在将插入失败
	auto ret = m.insert(make_pair("peach", "桃色"));
	if (ret.second)
		cout << "<peach, 桃色>不在map中, 已经插入" << endl;
	else
		cout << "键值为peach的元素已经存在：" << ret.first->first << "--->" <<
		ret.first->second << " 插入失败" << endl;

	// 删除key为"apple"的元素
	m.erase("apple");

	if (1 == m.count("apple"))
		cout << "apple还在" << endl;
	else
		cout << "apple被吃了" << endl;
}


int main()
{
	TestMap();
	system("pause");
	return 0;
}