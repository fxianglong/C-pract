#include"Threadcache.h"
#include<vector>
void UnitThreadTest()
{
	ThreadCache tc;
	vector<void*> v;
	for (size_t i = 0; i < 21; ++i)
	{
		v.push_back(tc.Allocte(7));
	}

	for (size_t i = 0;i<v.size();i++){
		printf("[%d]->%p\n", i, v[i]);
	}

	for (auto ptr : v)
	{
		tc.Deallocte(ptr, 7);
	}
}
int main()
{
	UnitThreadTest();
	system("pause");
	return 0;
}