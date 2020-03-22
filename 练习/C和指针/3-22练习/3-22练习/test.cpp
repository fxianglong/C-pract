//
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//struct player
//{
//	int w;
//	int h;
//};
//bool com_w(player p1, player p2)
//{
//	if (p1.w != p2.w)
//		return p1.w <= p2.w;
//	else
//		return p1.h>p2.h;
//}
//int main(void)
//{
//	int N;
//	int h;
//	int w;
//	int index;
//	vector<player> p;
//	while (cin >> N)
//	{
//		p.clear();
//
//		for (int i = 0; i<N; i++)
//		{
//			player pt;
//			cin >> index >> w >> h;
//			pt.w = w;
//			pt.h = h;
//			p.push_back(pt);
//		}
//		sort(p.begin(), p.end(), com_w);
//
//		vector<int> dp2(N + 1);
//		int max = 0;
//		dp2[0] = 1;
//		for (int i = 1; i<N; i++)
//		{
//			dp2[i] = 1;
//			for (int j = 0; j<i; j++)
//			{
//				if (p[j].h <= p[i].h && dp2[j] + 1 > dp2[i])
//					dp2[i] = dp2[j] + 1;
//			}
//		}
//		for (int i = 0; i<N; i++)
//		if (max < dp2[i])
//			max = dp2[i];
//		cout << max << endl;
//	}
//	system("pause");
//	return 0;
//}





#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

// NK表存放的是，在前n个学生中，取k个（必取第n个），所等得到的最大正乘积和最小负乘积。
long long NK_zheng[51][11];
long long NK_fu[51][11];

int main() {

	int N;
	cin >> N;

	vector<int> V(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> V[i];
	}

	int K, D;
	cin >> K >> D;

	for (int n = 1; n <= 50; n++) {
		for (int k = 1; k <= 10; k++) {
			NK_zheng[n][k] = LLONG_MIN;     // 代表无效值
			NK_fu[n][k] = LLONG_MAX;
		}
	}

	for (int n = 1; n <= N; n++) {
		if (V[n] >= 0)
			NK_zheng[n][1] = V[n];
		else
			NK_fu[n][1] = V[n];
	}

	for (int n = 2; n <= N; n++) {
		for (int k = 2; k <= K && k <= n; k++) {
			// 找到NK[...][k-1]中最大的正数和最小的负数。
			long long max = LLONG_MIN, min = LLONG_MAX;
			for (int temp = (k - 1 > n - D) ? (k - 1) : (n - D); temp <= n - 1; temp++) {     // 起始位置很重要
				if (max < NK_zheng[temp][k - 1])
					max = NK_zheng[temp][k - 1];
				if (min > NK_fu[temp][k - 1])
					min = NK_fu[temp][k - 1];
			}
			if (max != LLONG_MIN) {
				if (V[n] >= 0)
					NK_zheng[n][k] = max * V[n];
				else
					NK_fu[n][k] = max * V[n];
			}
			if (min != LLONG_MAX) {
				if (V[n] < 0 && NK_zheng[n][k] < min * V[n])
					NK_zheng[n][k] = min * V[n];
				else if (NK_fu[n][k] > min * V[n])
					NK_fu[n][k] = min * V[n];
			}
		}
	}

	// 在两个表的最后一列中，找出最大的乘积。
	long long max1 = LLONG_MIN, max2 = LLONG_MIN;
	for (int n = K; n <= N; n++) {
		if (max1 < NK_zheng[n][K])
			max1 = NK_zheng[n][K];
		if (max2 < NK_fu[n][K] && NK_fu[n][K] != LLONG_MAX)
			max2 = NK_fu[n][K];
	}

	max1 = max1 > max2 ? max1 : max2;

	cout << max1 << endl;
}