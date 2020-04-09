#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
void test_list()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(2);
	//l.uique();
//	sort(l.begin(),l.end());
	
	list<int>::iterator it=l.begin();
	while(it!=l.end()){
		cout<<*it<<endl;
		it++;
	}
}
int main(){

	test_list();
	return 0;
}
