//#include<iostream>
//using namespace std;
//
//void print1(int a, int b)
//{
//	if (a < b)
//		return;
//	else
//	{
//		cout << a%b<<" ";
//	}
//}
//int main()
//{
//	long long a, b, c, d;
//	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
//	print1(a, b);
//	if (a%b != 0)
//		printf("%lld/%lld", a%b, b);
//	system("pause");
//
//
//}



//#include <cstdio>
//#include <cstring>
//#include <string>
//using namespace std;
//
//char s[111];
//
//long long gcd(long long x, long long y) {
//	return y ? gcd(y, x % y) : x;
//}
//
//void print(long long x, long long y) {
//
//	if (y < 0) {
//		x = -x;
//		y = -y;
//	}
//	long long g = gcd((x < 0) ? (-x) : x, y);
//	x /= g;
//	y /= g;
//	if (x == 0) {
//		putchar('0');
//		return;
//	}
//	bool sign = false;
//	if (x < 0) {
//		sign = true;
//		printf("(-");
//		x = -x;
//	}
//	bool have = false;
//	if (x / y) {
//		printf("%lld", x / y);
//		have = true;
//	}
//	if (x % y) {
//		if (have) {
//			putchar(' ');
//		}
//		printf("%lld/%lld", x % y, y);
//	}
//	if (sign) {
//		putchar(')');
//	}
//}
//
//int main() {
//	long long a, b, c, d;
//	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
//	// a / b + c / d
//	print(a, b);
//	printf(" + ");
//	print(c, d);
//	printf(" = ");
//	print(a * d + b * c, b * d);
//	puts("");
//
//	print(a, b);
//	printf(" - ");
//	print(c, d);
//	printf(" = ");
//	print(a * d - b * c, b * d);
//	puts("");
//
//	print(a, b);
//	printf(" * ");
//	print(c, d);
//	printf(" = ");
//	print(a * c, b * d);
//	puts("");
//
//	print(a, b);
//	printf(" / ");
//	print(c, d);
//	printf(" = ");
//	if (c) {
//		print(a * d, b * c);
//	}
//	else {
//		printf("Inf");
//	}
//	puts("");
//	system("pause");
//	return 0;
//}



#include<iostream>
#include<string> 
using namespace std;
int c[21][21], n;
long long solve(string pre, string post){
	long long sum = 1;
	int num = 0, k = 0, i;
	pre.erase(pre.begin());
	post = post.substr(0, post.length() - 1);
	while (k<pre.length())
	for (i = 0; i<post.length(); i++)
	if (pre[k] == post[i]){
		sum *= solve(pre.substr(k, i - k + 1), post.substr(k, i - k + 1));
		num++, k = i + 1; break;
	}
	sum *= c[num][n];
	return sum;
}
void init(){
	int i, j;
	c[0][1] = c[1][1] = 1;
	for (i = 2; i<21; i++)
	for (c[0][i] = 1, j = 1; j <= i; j++)
	if (i == j) c[j][i] = 1;
	else c[j][i] = c[j - 1][i - 1] + c[j][i - 1];

}
int main(){
	string pre, post;
	init();
	while (cin >> n >> pre >> post&&n)
		cout << solve(pre, post) << endl;
}