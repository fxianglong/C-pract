#include"AVLTree.h"
#include"map_set.h"

struct Less{
	bool operator()(int x1, int x2)
	{
		return x1 < x2;
	} 
};
int main()
{
	Less less;
	cout << less.operator()(1, 2) << endl;//·Âº¯Êý
	vector<int> v = { 1, 23, 4, 5, 6, 7 };
	forward_list<int> fl = { 21, 33, 45, 6, 7, 5 };
	list<int> l = { 3, 4, 6, 7, 8, 9, 7, 9 };
	sort(v.begin(), v.end());
	//sort(fl.begin(), fl.end());
	//sort(l.begin(), l.end());
	print_vector(v);
	return 0;
}