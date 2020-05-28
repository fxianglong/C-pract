class Solution {
public:
	string src;
	size_t ptr;

	int getDigits() {
		int ret = 0;
		while (ptr < src.size() && isdigit(src[ptr])) {
			ret = ret * 10 + src[ptr++] - '0';
		}
		return ret;
	}

	string getString() {
		if (ptr == src.size() || src[ptr] == ']') {
			// String -> EPS
			return "";
		}

		char cur = src[ptr]; int repTime = 1;
		string ret;

		if (isdigit(cur)) {
			// String -> Digits [ String ] String
			// ���� Digits
			repTime = getDigits();
			// ����������
			++ptr;
			// ���� String
			string str = getString();
			// ����������
			++ptr;
			// �����ַ���
			while (repTime--) ret += str;
		}
		else if (isalpha(cur)) {
			// String -> Char String
			// ���� Char
			ret = string(1, src[ptr++]);
		}

		return ret + getString();
	}

	string decodeString(string s) {
		src = s;
		ptr = 0;
		return getString();
	}
};


class Solution {
public:
	string getDigits(string &s, size_t &ptr) {
		string ret = "";
		while (isdigit(s[ptr])) {
			ret.push_back(s[ptr++]);
		}
		return ret;
	}

	string getString(vector <string> &v) {
		string ret;
		for (const auto &s : v) {
			ret += s;
		}
		return ret;
	}

	string decodeString(string s) {
		vector <string> stk;
		size_t ptr = 0;

		while (ptr < s.size()) {
			char cur = s[ptr];
			if (isdigit(cur)) {
				// ��ȡһ�����ֲ���ջ
				string digits = getDigits(s, ptr);
				stk.push_back(digits);
			}
			else if (isalpha(cur) || cur == '[') {
				// ��ȡһ����ĸ����ջ
				stk.push_back(string(1, s[ptr++]));
			}
			else {
				++ptr;
				vector <string> sub;
				while (stk.back() != "[") {
					sub.push_back(stk.back());
					stk.pop_back();
				}
				reverse(sub.begin(), sub.end());
				// �����ų�ջ
				stk.pop_back();
				// ��ʱջ��Ϊ��ǰ sub ��Ӧ���ַ���Ӧ�ó��ֵĴ���
				int repTime = stoi(stk.back());
				stk.pop_back();
				string t, o = getString(sub);
				// �����ַ���
				while (repTime--) t += o;
				// ������õ��ַ�����ջ
				stk.push_back(t);
			}
		}

		return getString(stk);
	}
};
