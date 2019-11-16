//#include<iostream>
//#include<string>
//using namespace std;
//int Length(string s)
//{
//	int ret = s.size();
//	if (ret <= 4)
//		return 5;
//	else if (ret >= 5 && ret <= 7)
//		return 10;
//	else return 25;
//}
//
//int main()
//{
//	string s;
//	while (getline(cin, s)){
//		int sum = 0;
//		sum += Length(s);
//		bool f1 = false;
//		bool f2 = false;
//		bool f3 = false;
//		bool f4 = false;
//		int count1 = 0;
//		int count2 = 0;
//		for (unsigned int i = 0; i < s.length(); i++) {
//			if (s[i] >= 'A'&&s[i] <= 'Z'){
//				f1 = true;
//			}
//			else if (s[i] >= 'a'&&s[i] <= 'z'){
//				f2 = true;
//			}
//			if (s[i] >= '0'&&s[i] <= '9'){
//				f3 = true;
//				//System.out.println(str.charAt(i));
//				count1++;
//			}
//			if (!(s[i] >= '0'&&s[i] <= '9' || s[i] >= 'A'
//				&&s[i] <= 'Z' || s[i] >= 'a'
//				&&s[i] <= 'z')){
//				f4 = true;
//				count2++;
//			}
//		}
//		if (f1&&f2){
//			sum += 20;
//		}
//		else if (!f1&&!f2){
//			sum += 0;
//		}
//		else {
//			sum += 10;
//		}
//		//System.out.println(sum);
//		if (count1 == 1){
//			sum += 10;
//		}
//		else if (count1 > 1){
//			sum += 20;
//		}
//		//System.out.println(sum);
//		if (count2 == 1){
//			sum += 10;
//		}
//		else if (count2 > 1){
//			sum += 25;
//		}
//		//System.out.println(sum);
//		if (f1&&f2&&f3&&f4){
//			sum += 5;
//		}
//		else if (!f1&&f2&&f3&&f4 || f1&&!f2&&f3&&f4){
//			sum += 3;
//		}
//		else if (!f1&&f2&&f3&&!f4 || f1&&!f2&&f3&&!f4){
//			sum += 2;
//		}
//		//System.out.println("sum :"+sum);
//		if (sum >= 90){
//			cout << "VERY_SECURE" << endl;
//		}
//		else if (sum >= 80){
//			cout << "SECURE" << endl;
//		}
//		else if (sum >= 70){
//			cout << "VERY_STRONG" << endl;
//		}
//		else if (sum >= 60){
//			cout << "STRONG" << endl;
//		}
//		else if (sum >= 50){
//			cout << "AVERAGE" << endl;
//		}
//		else if (sum >= 25){
//			cout << "WEAK" << endl;
//		}
//		else if (sum >= 0){
//			cout << "VERY_WEAK" << endl;
//		}
//	}
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	int n; 
//	while (cin>>n)
//	{
//		int max = 0; int sum = 0;
//		while (n)
//		{
//			if (n % 2 == 1)
//				sum += 1;
//			else sum = 0;
//			max = sum;
//			n = n / 2;
//		}
//		cout << max << endl;
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	cin >> n;
//	int max = 0; int count = 0;
//	while (n)
//	{
//		while (n & 1 == 1){
//			count++;
//			n = n / 2;
//		}
//		max = count>max ? count : max;
//		n = n >> 1;
//	}
//	cout << count << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n){
//		int count = 0; int max = 0;
//		while (n)
//		{
//			while ((n & 1) == 1){
//				count++;
//				n = n / 2;
//			}
//			max = (count>max ? count : max);
//			n = n >> 1;
//		}
//		cout << count << endl;
//	}
//	return 0;
//}

#include<iostream>
using namespace std;
int max(int a, int b)
{
	return a>b ? a : b;
}
int min(int a, int b)
{
	return a<b ? a : b;
}
int seekroot(int n)
{
	if (n % 2 == 0)
		return n / 2;

	else return (n - 1)/2;
}
int getLCA(int a, int b) {
	if (a == b) return a;
	int mx = max(a, b); int mn = min(a, b);
	while (mn>1)
	{
		if (seekroot(mx) != mn)
		{
			int temp = seekroot(mx);
			mx = max(seekroot(mx), mn);
			mn = min(mn, temp);
		}
		else
			return mn;
	}
	return 1;
}
int main()
{
	int a = 0, b = 0;
	cin >> a >> b;
	cout << getLCA(a, b) << endl;
	system("pause");
	return 0;
}