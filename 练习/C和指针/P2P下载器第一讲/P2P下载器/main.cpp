#include"util.hpp"
int main()
{
	std::vector<Adapter> list;
	AdapterUtil::GetAllAdapter(&list);
	system("pause");
	return 0;

}