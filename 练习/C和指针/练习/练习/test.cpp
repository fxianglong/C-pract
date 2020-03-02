//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int flag = 0;
//bool Issushu(int n)
//{
//	for (int i = 2; i < n; i++)
//	{
//		if (n%i == 0)
//			return false;
//	}
//	return true;
//}
//void Fenjie(int x, vector<int>& res)
//{
//	for (int i = 2; i <= x; i++)
//	{
//		if (Issushu(i) && (x%i) == 0)
//		{
//			res.push_back(i);
//			if (x == i)
//			{
//				flag = 1;
//				return;
//			}
//			else
//				Fenjie(x / i, res);
//		}
//		if (flag == 1)
//			return;
//	}
//}
//int main()
//{
//	int x = 0;
//	while (cin >> x)
//	{
//		flag = 0;
//		vector<int> ans;
//		Fenjie(x, ans);
//		cout << x << "=";
//		for (int i = 0; i < ans.size(); i++)
//		{
//			cout << ans[i];
//			if (i + 1 < ans.size())
//				cout << "*";
//			else
//			{
//				cout << endl;
//			}
//		}
//	}
//	return 0;
//}
//

//
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int n;
//	while (scanf("%d", &n) != EOF)
//	{
//		printf("%d =", n);
//		int i;
//		for (i = 2; i <= sqrt(n); i++)
//		{
//			while (n != i)
//			{
//				if (n%i == 0)
//				{
//					printf(" %d *", i);
//					n /= i;
//				}
//				else
//					break;
//			}
//		}
//		printf(" %d\n", n);
//	}
//	return 0;
//}


//#include<iostream>
//#include<vector>
//using namespace std;
//vector<int> leap = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//vector<int> nor = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//bool isLeap(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//		return true;
//	else
//		return false;
//}
//
//int oneDay(int year)
//{
//	int days = (year - 2000) / 4 * (365 * 3 + 366);
//	if ((year - 2000) % 4 == 0)
//		return days;
//	else
//		days += 366 + 365 * ((year - 2000) % 4 - 1);
//	return days;
//}
//
//
//int judge(int year, int mon, int day)
//{
//	int days = oneDay(year);
//	if (isLeap(year))
//	for (int i = 0; i < mon - 1; i++)
//		days = days + leap[i];
//	else
//	for (int i = 0; i < mon - 1; i++)
//		days = days + nor[i];
//	days += day - 1;
//
//	int tmp = days % 7;
//	tmp += 6;
//	if (tmp > 7)
//		return tmp - 7;
//	else
//		return tmp;
//}
//void print(int year, int mon, int day)
//{
//	cout << year << '-';
//	if (mon >= 10)
//		cout << mon << '-';
//	else
//		cout << '0' << mon << '-';
//	if (day >= 10)
//		cout << day << endl;
//	else
//		cout << '0' << day << endl;
//}
//
//void Year(int year)
//{
//
//	print(year, 1, 1);
//
//	int t = judge(year, 1, 1);
//	if (t == 1)
//		print(year, 1, 15);
//	else {
//		int tmp = 7 - t + 2;
//		tmp += 14;
//		print(year, 1, tmp);
//	}
//
//	t = judge(year, 2, 1);
//	if (t == 1)
//		print(year, 2, 15);
//	else {
//		int tmp = 7 - t + 2;
//		tmp += 14;
//		print(year, 2, tmp);
//	}
//
//	t = judge(year, 5, 31);
//	if (t == 1)
//		print(year, 5, 31);
//	else
//		print(year, 5, 31 - t + 1);
//
//	print(year, 7, 4);
//
//	t = judge(year, 9, 1);
//	if (t == 1)
//		print(year, 9, 1);
//	else
//		print(year, 9, 7 - t + 2);
//
//	t = judge(year, 11, 1);
//	if (t <= 4)
//		print(year, 11, 21 + 5 - t);
//	else
//		print(year, 11, 7 - t + 1 + 21 + 3 + 1);
//
//	print(year, 12, 25);
//}
//
//int main()
//{
//	int year;
//	while (cin >> year){
//		Year(year);
//	}
//	return 0;
//}



#include <iostream>
using namespace std;
int WeekToDay(int y, int m, int c, int w, bool B){
	int d, week, i;
	if (m == 1){ m = 13; y--; }
	if (m == 2){ m = 14; y--; }
	i = 0;
	for (d = B ? 1 : 31; d <= B ? 31 : 1; B ? (d++) : (d--)){
		week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
		if (week + 1 == w) ++i;
		if (i == c) break;
	}
	return d;
}

int main(void){
	int y;
	while (cin >> y){
		cout << y << "-01-01" << endl;
		printf("%d-01-%02d\n", y, WeekToDay(y, 1, 3, 1, 1));
		printf("%d-02-%02d\n", y, WeekToDay(y, 2, 3, 1, 1));
		printf("%d-05-%02d\n", y, WeekToDay(y, 5, 1, 1, 0));
		cout << y << "-07-04" << endl;
		printf("%d-09-%02d\n", y, WeekToDay(y, 9, 1, 1, 1));
		printf("%d-11-%02d\n", y, WeekToDay(y, 11, 4, 4, 1));
		cout << y << "-12-25" << endl << endl;
	}
	return 0;
}