#include <bits/stdc++.h>
using namespace std;
int n;
string str;
vector<string> arr;

bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	return a.size() < b.size();
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			string num;
			while (str[j] - '0' >= 0 && str[j] - '0' <= 9) {
				num += str[j];
				j++;
				if (j == str.size()) break;
			}
			if (num.size()) {
				while (num.size() != 1 && num[0] == '0') {
					num = num.substr(1);
				}
				arr.push_back(num);

			}
		}
	}
	sort(arr.begin(), arr.end(),cmp);
	for (auto i : arr)
		cout << i << '\n';
}