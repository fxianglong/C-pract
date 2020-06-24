class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int best = 1e7;

		// ���ݲ�ֵ�ľ���ֵ�����´�
		auto update = [&](int cur) {
			if (abs(cur - target) < abs(best - target)) {
				best = cur;
			}
		};

		// ö�� a
		for (int i = 0; i < n; ++i) {
			// ��֤����һ��ö�ٵ�Ԫ�ز����
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			// ʹ��˫ָ��ö�� b �� c
			int j = i + 1, k = n - 1;
			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				// �����Ϊ target ֱ�ӷ��ش�
				if (sum == target) {
					return target;
				}
				update(sum);
				if (sum > target) {
					// ����ʹ��� target���ƶ� c ��Ӧ��ָ��
					int k0 = k - 1;
					// �ƶ�����һ������ȵ�Ԫ��
					while (j < k0 && nums[k0] == nums[k]) {
						--k0;
					}
					k = k0;
				}
				else {
					// �����С�� target���ƶ� b ��Ӧ��ָ��
					int j0 = j + 1;
					// �ƶ�����һ������ȵ�Ԫ��
					while (j0 < k && nums[j0] == nums[j]) {
						++j0;
					}
					j = j0;
				}
			}
		}
		return best;
	}
};