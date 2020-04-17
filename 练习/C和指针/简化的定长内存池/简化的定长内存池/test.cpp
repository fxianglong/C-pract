#include"memoryPool.h"
#include <vector>
#include <time.h>

void TestObjectPool()
{
	MemoryPool<std::string> pool;
	std::string* p1 = pool.New("1111");
	std::string* p2 = pool.New("2222");

	cout << p1 << endl;
	cout << p2 << endl;

	pool.Delete(p1);
	pool.Delete(p2);

	std::string* p3 = pool.New("3333");
	std::string* p4 = pool.New("4444");
	std::string* p5 = pool.New("5555");

	cout << p3 << endl;
	cout << p4 << endl;
	cout << p5 << endl;
}


void BenchMark()
{
	size_t n = 10000;

	std::vector<std::string*> v1;
	v1.reserve(n);
	size_t begin1 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		v1.push_back(new std::string);
	}

	for (size_t i = 0; i < n; ++i)
	{
		delete v1[i];
	}

	v1.clear();
	for (size_t i = 0; i < n; ++i)
	{
		v1.push_back(new std::string);
	}

	for (size_t i = 0; i < n; ++i)
	{
		delete v1[i];
	}

	size_t end1 = clock();

	std::vector<std::string*> v2;
	v2.reserve(n);
	size_t begin2 = clock();
	MemoryPool<std::string> pool;
	for (size_t i = 0; i < n; ++i)
	{
		v2.push_back(pool.New(""));
	}

	for (size_t i = 0; i < n; ++i)
	{
		pool.Delete(v2[i]);
	}
	v2.clear();

	for (size_t i = 0; i < n; ++i)
	{
		v2.push_back(pool.New(""));
	}

	for (size_t i = 0; i < n; ++i)
	{
		pool.Delete(v2[i]);
	}
	size_t end2 = clock();

	cout << end1 - begin1 << endl;
	cout << end2 - begin2 << endl;
}

int main()
{
	TestObjectPool();
	BenchMark();
	system("pause");
	return 0;
}