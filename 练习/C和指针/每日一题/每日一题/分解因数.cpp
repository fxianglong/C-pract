#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int flag = 0;
bool Issushu(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}
void Fenjie(int x,vector<int>& res)
{
	for (int i = 2; i <= x; i++)
	{
		if (Issushu(i)&&(x%i)==0)
		{
			res.push_back(i);
			if (x == i)
			{
				flag = 1;
				return;
			}
			else
			Fenjie(x / i,res);
		}
		if (flag == 1)
			return;
	}
}
int main()
{
	int x = 0;
	cin >> x;
	vector<int> ans;
	Fenjie(x,ans);
	cout << x<<"=";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
		if (i + 1 < ans.size())
			cout << "*";
	}
	system("pause");
	return 0;
}

//#include<iostream>
//using namespace std;
//int a;
//
//void f(int m, int n) {
//	for (int i = m; i <= n / i; ++i)
//	if (n % i == 0){
//		a++;
//		f(i, n / i);
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	while (n--){
//		a = 1;
//		int x;
//		cin >> x;
//		f(2, x);
//		cout << a << endl;
//	}
//}
