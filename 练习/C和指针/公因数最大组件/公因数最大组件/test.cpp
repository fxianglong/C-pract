#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<int> F;
		int father(int x) {
			if (x != F[x]) F[x] = father(F[x]);
			return F[x];
		}
	int largestComponentSize(vector<int>& A) {
		int M = *max_element(A.begin(), A.end());
		F.resize(M + 1);
		for (int i = 2; i <= M; ++i) {
			F[i] = i;
		}
		vector<bool> isCandidate(M + 1, false);
		for (auto x : A) {
			isCandidate[x] = true;
		}
		vector<bool> isPrime(M + 1, true);
		for (int i = 2; i <= M; ++i) {
			if (isPrime[i]) {
				int t = isCandidate[i] ? i : -1;
				for (int j = i + i; j <= M; j += i) {
					if (isCandidate[j]) {
						if (t == -1) {
							t = j;
						}
						else {
							F[father(j)] = father(t);
						}
					}
					isPrime[j] = false;
				}
			}
		}
		map<int, int> counts;
		for (auto x : A) {
			++counts[father(x)];
		}
		int res = 0;
		for (auto& p : counts) {
			res = max(res, p.second);
		}
		return res;
	}
};
int main()
{
	Solution as;
	vector<int> ans = { 3, 5, 7, 8, 9, 14 };
	cout << as.largestComponentSize(ans) << endl;
	
	system("pause");
	return 0;
}