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
//	// �������е�Ԫ�ؽ����ۼ�
//	vector<int> v{ 7, 8, 9 };
//	cout << accumulate(v.begin(), v.end(), 0) << endl;
//
//	// �������е�ÿ��Ԫ�س�2��Ȼ���ۼ�
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
//	// ͳ��10��v1�г��ֵĴ���
//	vector<int> v1{ 10, 20, 30, 30, 20, 10, 10, 20 };
//	cout << count(v1.begin(), v1.end(), 10) << endl;
//
//	// ͳ��v2���ж��ٸ�ż��
//	vector<int> v2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	cout << count_if(v2.begin(), v2.end(), IsOdd) << endl;
//	system("pause");
//	return 0;
//}


//
//// ��[first, last)�в���value��һ�γ��ֵ�λ�ã��ҵ����ظ�Ԫ�ص�λ�ã����򷵻�last
//// ʱ�临�Ӷ�O(N)
//template<class InputIterator, class T>
//InputIterator find(InputIterator first, InputIterator last, const T& value)
//{
//	for (; first != last; first++) if (*first == value) break;
//	return first;
//}
//
//// ��[first, last)�в�������pred������Ԫ�ص�һ�γ��ֵ�λ�ã��ҵ����ظ�λ�ã����򷵻�last
//// ʱ�临�Ӷ�O(N)
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
//	// �Ҹ�������ǰ4����С��Ԫ��, Ԫ�����մ洢��v1��ǰ4��λ��
//	vector<int> v1{ 4, 1, 8, 0, 5};
//	partial_sort(v1.begin(), v1.begin() + 4, v1.end());
//	// �Ҹ�������ǰ4������Ԫ��, Ԫ�����մ洢��v1��ǰ4��λ��
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
//	// ��������Ԫ�طָ��������ż��������
//	auto div = partition(v.begin(), v.end(), IsOdd);
//
//	// ��ӡ[begin, div)��Ԫ��
//	for (auto it = v.begin(); it != div; ++it)
//		cout << *it << " ";
//	cout << endl;
//
//	// ��ӡ[div, end)��Ԫ��
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


//// Ԫ�ز����ʱ���ú�һ����ǰһ��Ԫ�ظ��ǵ�
//template <class ForwardIterator>
//ForwardIterator unique(ForwardIterator first, ForwardIterator last);
//
//// ���Ԫ�ز�����pred����ʱ���ú�һ����ǰһ�����ǵ�
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
//	�Ӵ�ӡ�Ľ�����Կ�����
//	1. unique��û�н������ظ���Ԫ��ɾ��������ֵɾ����һ��9����Ϊuniqueɾ���������ڵ��ظ�
//	Ԫ�أ�������Ԫ����ֻ��һ��9�ظ�����
//	2. uniqueɾ��ʱֻ���ú���Ԫ�ؽ�ǰ���ظ�λ�ø��ǵ��ˣ���û�дﵽ����ɾ������Ҫ����ɾ
//	��������Ҫerase���
//	*/
//	v.erase(it, v.end());
//
//	// ����뽫�����������ظ��Ե�Ԫ��ɾ�����������ȶ������е�Ԫ�ؽ�������
//	for (auto e : v)
//		cout << e << " ";
//	cout << endl;
//
//	// �ȶ������е�Ԫ�ؽ����������ظ���Ԫ�ط�������λ��
//	sort(v.begin(), v.end());
//	for (auto e : v)
//		cout << e << " ";
//	cout << endl;
//
//	// ʹ��unique���ظ���Ԫ�ظ��ǵ�
//	it = unique(v.begin(), v.end());
//
//	// ��������Ч��Ԫ���Ƴ�
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
//	// ��Ϊnext_permutation�����ǰ��մ����ֵ����ȡ��һ��������ϵ�
//	// ���������ʱ���뱣֤�����������
//	vector<int> v = { 4, 1, 2, 3 };
//	sort(v.begin(), v.end());
//	do
//	{
//		cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
//	} while (next_permutation(v.begin(), v.end()));
//	cout << endl;
//
//	// ��Ϊprev_permutation�����ǰ���С���ֵ����ȡ��һ��������ϵ�
//	// ���������ʱ���뱣֤�����ǽ����
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
//	// ��������ÿ��Ԫ�س�2
//	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	for_each(v.begin(), v.end(), Mul2());
//	for (auto e : v)
//		cout << e << " ";
//	cout << endl;
//
//	// ɾ��������3�ı���
//	auto pos = remove_if(v.begin(), v.end(), Mod3());
//	v.erase(pos, v.end());
//
//	// �������е�Ԫ�ش�ӡ����
//	// ע�⣺���ڹ��ܼ򵥵Ĳ���������ʹ��C++11�ṩ��lambda���ʽ������
//	// lambda���ʽʵ�ּ򵥣����ڵײ���º�����ԭ����ͬ���������Ὣlambda���ʽת��Ϊ�º���
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
	int sco=0;//����ɼ��ı���
	int count = 0;//����ɼ��ļ���
	int V[N] = { 0 };//����40���ռ�����飬����ʼ��Ϊ0
	printf("INPUT num:");
	for (int i = 0; i < N; i++)//����ɼ�
	{
		scanf("%d", &V[i]);
		if (V[i] < 0)//�ɼ�����Υ����˵���ɼ�������ϣ���������
			break;
		count++;//����һ���ɼ����ɼ�����+1
		printf("INPUT num:");
	}
	printf("sort:\n");
	for (int i = 0; i < count; i++)//�����Ч�ɼ�
		printf("%3d", V[i]);
	return 0;
}