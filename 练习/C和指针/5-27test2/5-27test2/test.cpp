class Solution {
public:
	int subarraysDivByK(vector<int>& A, int K) {
		unordered_map<int, int> record = { { 0, 1 } };
		int sum = 0;
		for (int elem : A) {
			sum += elem;
			// ע�� C++ ȡģ�������ԣ���������Ϊ����ʱȡģ���Ϊ��������Ҫ����
			int modulus = (sum % K + K) % K;
			++record[modulus];
		}

		int ans = 0;
		for (auto[x, cx] : record) {
			ans += cx * (cx - 1) / 2;
		}
		return ans;
	}
};


class Solution {
public:
	int subarraysDivByK(vector<int>& A, int K) {
		unordered_map<int, int> record = { { 0, 1 } };
		int sum = 0, ans = 0;
		for (int elem : A) {
			sum += elem;
			// ע�� C++ ȡģ�������ԣ���������Ϊ����ʱȡģ���Ϊ��������Ҫ����
			int modulus = (sum % K + K) % K;
			if (record.count(modulus)) {
				ans += record[modulus];
			}
			++record[modulus];
		}
		return ans;
	}
};
