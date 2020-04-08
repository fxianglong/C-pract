#include<iostream>
using namespace std;

//#include<iostream>
//using namespace std;
//
//int main(){
//	cout << "hello world" << endl;
//}
//


//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(){}
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d(1990,1,1);
//	return 0;
//}

//class A{
//public:
//	A(int a)
//	:_a(a){
//	}
//
//private:
//	int _a;
//};
//int main()
//{
//	A aal(1);//构造
//	A aa2 = 2;//构造+拷贝构造+优化==构造
//	return 0;
//}


class Sum{
public:
	Sum(){
		_sum += _i;
		++_i;
	}
	static void Init(){
		_sum = 0;
		_i = 1;
	}
	static int sum(){
		return _sum;
	}
private:
	static int _sum;
	static int _i;
};
int Sum::_sum = 0;
int Sum::_i = 0;
int Sum_Solution(int n) {
	Sum::Init();
	Sum* p = new Sum[n];
	delete[] p;
	Sum::sum();
}
int main()
{
	Sum_Solution(5);
	system("pause");
};

