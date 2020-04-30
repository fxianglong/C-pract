#include <numeric>
#include <vector>
#include<string>
#include<iostream>
#include<list>
#include <algorithm>
using namespace std;

//struct Mul2
//{
//	int operator()(int x, int y) { return x + 2 * y; }
//};
//
//
//int main()
//{
//	// 对区间中的元素进行累加
//	vector<int> v{ 7, 8, 9 };
//	cout << accumulate(v.begin(), v.end(), 0) << endl;
//
//	// 对区间中的每个元素乘2，然后累加
//	cout << accumulate(v.begin(), v.end(), 0, Mul2()) << endl;
//	system("pause");
//	return 0;
//}





//bool IsOdd(int i)
//{
//	return ((i % 2) == 1);
//}
//
//int main()
//{
//	// 统计10在v1中出现的次数
//	vector<int> v1{ 10, 20, 30, 30, 20, 10, 10, 20 };
//	cout << count(v1.begin(), v1.end(), 10) << endl;
//
//	// 统计v2中有多少个偶数
//	vector<int> v2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	cout << count_if(v2.begin(), v2.end(), IsOdd) << endl;
//	system("pause");
//	return 0;
//}


//
//// 在[first, last)中查找value第一次出现的位置，找到返回该元素的位置，否则返回last
//// 时间复杂度O(N)
//template<class InputIterator, class T>
//InputIterator find(InputIterator first, InputIterator last, const T& value)
//{
//	for (; first != last; first++) if (*first == value) break;
//	return first;
//}
//
//// 在[first, last)中查找满足pred条件的元素第一次出现的位置，找到返回该位置，否则返回last
//// 时间复杂度O(N)
//template<class InputIterator, class Predicate>
//InputIterator find_if(InputIterator first, InputIterator last, Predicate pred)
//{
//	for (; first != last; first++) if (pred(*first)) break;
//	return first;
//}

//
//int main()
//{
//	vector<int> v{ 2, 6, 5, 8 };
//	list<int> L{ 9, 3, 0, 5, 7 };
//
//	sort(v.begin(), v.end());
//	L.sort();
//
//	vector<int> vRet(v.size() + L.size());
//	merge(v.begin(), v.end(), L.begin(), L.end(), vRet.begin());
//
//	for (auto e : vRet)
//		cout << e << " ";
//	cout << endl;
//	system("pause");
//	return 0;
//}


#include <algorithm>
#include <vector>
#include <functional>

//int main()
//{
//	// 找该区间中前4个最小的元素, 元素最终存储在v1的前4个位置
//	vector<int> v1{ 4, 1, 8, 0, 5};
//	partial_sort(v1.begin(), v1.begin() + 4, v1.end());
//	// 找该区间中前4个最大的元素, 元素最终存储在v1的前4个位置
//	vector<int> v2{ 4, 1, 8, 0, 5};
//	partial_sort(v2.begin(), v2.begin() + 4, v2.end(), greater<int>());
//	system("pause");
//	return 0;
//}


//bool IsOdd(int i)
//{
//	return (i % 2) == 1;
//}
//
//int main()
//{
//	vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	// 将区间中元素分割成奇数和偶数两部分
//	auto div = partition(v.begin(), v.end(), IsOdd);
//
//	// 打印[begin, div)的元素
//	for (auto it = v.begin(); it != div; ++it)
//		cout << *it << " ";
//	cout << endl;
//
//	// 打印[div, end)的元素
//	for (auto it = div; it != v.end(); ++it)
//		cout << " " << *it;
//	cout << endl;
//	system("pause");
//	return 0;
//}



//int fch(char* p)
//{
//	int count = 0;
//	while (*p != '\0')
//	{
//		if (*p > 'A'&&*p < 'Z')
//			count++;
//		p++;
//	}
//	return count;
//}
//
//int main()
//{
//	char ans[100];
//	scanf("%s", &ans);
//	cout << fch(ans) << endl;
//	system("pause");
//	return 0;
//}


//#include<stdio.h>
//#define N 256
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int ans[N][N];
//	for (int i = 0; i < n;i++)
//	for (int j = 0; j < n; j++)
//	{
//		scanf("%d", &ans[i][j]);
//	}
//	int count = 0;
//	for (int i = 0; i < n;i++)
//	for (int j = 0; j < n; j++)
//	{
//		ans[i][j] += 10;
//		if (ans[i][j]>15)
//		{
//			ans[i][j] = 0;
//			count++;
//		}
//	}
//	for (int i = 0; i < n;i++)
//	for (int j = 0; j < n; j++)
//	{
//		printf("%d", ans[i][j]);
//	}
//	return 0;
//}


//// 元素不相等时，用后一个将前一个元素覆盖掉
//template <class ForwardIterator>
//ForwardIterator unique(ForwardIterator first, ForwardIterator last);
//
//// 如果元素不满足pred条件时，用后一个将前一个覆盖掉
//template <class ForwardIterator, class BinaryPredicate>
//ForwardIterator unique(ForwardIterator first, ForwardIterator last,
//	BinaryPredicate pred);
//
//template <class ForwardIterator>
//ForwardIterator unique(ForwardIterator first, ForwardIterator last)
//{
//	ForwardIterator result = first;
//	while (++first != last)
//	{
//		if (!(*result == *first))  // or: if (!pred(*result,*first)) for the pred 
//			version
//			*(++result) = *first;
//	}
//	return ++result;
//}



//#include <algorithm>
//#include <vector>
//
//int main()
//{
//	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	auto it = unique(v.begin(), v.end());
//
//	for (auto e : v)
//		cout << e << " ";
//	cout << endl;
//
//	/*
//	从打印的结果可以看出：
//	1. unique并没有将所有重复的元素删除掉，而值删除了一个9，因为unique删除的是相邻的重复
//	元素，而上述元素中只有一个9重复相邻
//	2. unique删除时只是用后面元素将前面重复位置覆盖掉了，并没有达到真正删除，若要真正删
//	除，还需要erase配合
//	*/
//	v.erase(it, v.end());
//
//	// 如果想将区间中所有重复性的元素删除掉，可以先对区间中的元素进行排序
//	for (auto e : v)
//		cout << e << " ";
//	cout << endl;
//
//	// 先对区间中的元素进行排序，另重复的元素放在相邻位置
//	sort(v.begin(), v.end());
//	for (auto e : v)
//		cout << e << " ";
//	cout << endl;
//
//	// 使用unique将重复的元素覆盖掉
//	it = unique(v.begin(), v.end());
//
//	// 将后面无效的元素移除
//	v.erase(it, v.end());
//	for (auto e : v)
//		cout << e << " ";
//	cout << endl;
//	return 0;
//}



//#include <algorithm>
//#include <vector>
//#include <functional>
//
//int main()
//{
//	// 因为next_permutation函数是按照大于字典序获取下一个排列组合的
//	// 因此在排序时必须保证序列是升序的
//	vector<int> v = { 4, 1, 2, 3 };
//	sort(v.begin(), v.end());
//	do
//	{
//		cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
//	} while (next_permutation(v.begin(), v.end()));
//	cout << endl;
//
//	// 因为prev_permutation函数是按照小于字典序获取下一个排列组合的
//	// 因此在排序时必须保证序列是降序的
//	//sort(v.begin(), v.end());
//	sort(v.begin(), v.end(), greater<int>());
//	do
//	{
//		cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
//	} while (prev_permutation(v.begin(), v.end()));
//	return 0;
//}


//template < class T, class Container = deque<T> >
//class stack { ... };
//
//template < class T, class Container = deque<T> >
//class queue { ... };

#include <vector>
#include <algorithm>
//class Mul2
//{
//public:
//	void operator()(int& data)
//	{
//		data <<= 1;
//	}
//};
//
//class Mod3
//{
//public:
//	bool operator()(int data)
//	{
//		return 0 == data % 3;
//	}
//};
//
//int main()
//{
//	// 给容器中每个元素乘2
//	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	for_each(v.begin(), v.end(), Mul2());
//	for (auto e : v)
//		cout << e << " ";
//	cout << endl;
//
//	// 删除容器中3的倍数
//	auto pos = remove_if(v.begin(), v.end(), Mod3());
//	v.erase(pos, v.end());
//
//	// 将容器中的元素打印出来
//	// 注意：对于功能简单的操作，可以使用C++11提供的lambda表达式来代替
//	// lambda表达式实现简单，其在底层与仿函数的原理相同，编译器会将lambda表达式转换为仿函数
//	for_each(v.begin(), v.end(), [](int data){cout << data << " "; });
//	cout << endl;
//	return 0;
//}

//
//int main()
//{
//	int* p = (int*)malloc(1024*1024*1024);
//	free(p);
//	system("pause");
//	return 0;
//}


#include<stdio.h>
#define N 40

int main()
{
	int sco=0;//输入成绩的变量
	int count = 0;//输入成绩的计数
	int V[N] = { 0 };//开辟40个空间的数组，并初始化为0
	printf("INPUT num:");
	for (int i = 0; i < N; i++)//输入成绩
	{
		scanf("%d", &V[i]);
		if (V[i] < 0)//成绩输入违法，说明成绩输入完毕，跳出输入
			break;
		count++;//输入一个成绩，成绩计数+1
		printf("INPUT num:");
	}
	printf("sort:\n");
	for (int i = 0; i < count; i++)//输出有效成绩
		printf("%3d", V[i]);
	return 0;
}