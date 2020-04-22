#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<forward_list>
#include<algorithm>
#include<list>
void print_vector(const vector<int>&_v)
{
	auto cit = _v.begin();
	while (cit != _v.end())
	{
		cout << *cit << " ";
		cit++;
	}
	cout << endl;
}