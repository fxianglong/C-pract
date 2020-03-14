//#include<iostream>
//#include<vector>
//using namespace std;
//
//long int Failrec(int n)
//{
//	if (n<2)
//		return 0;
//	if (n == 2)
//		return 1;
//	if (n == 3)
//			return 2;
//	return (n - 1)*(Failrec(n - 1) + Failrec(n - 2));
//}
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int count = 0;
//		cout << Failrec(n) << endl;
//	}
//	return 0;
//}




#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	while (cin >> n){
		vector<int> height(n, 0);
		for (int i = 0; i < n; i++){
			cin >> height[i];
		}

		vector<int> f(n, 1);
		int result = 1;
		for (int i = 1; i < n; i++){
			for (int j = 0; j < i; j++){
				if (height[i] > height[j]){
					f[i] = max(f[i], f[j] + 1);
				}
			}
			result = max(result, f[i]);
		}

		cout << result << endl;
	}
}