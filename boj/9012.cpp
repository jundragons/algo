#include <bits/stdc++.h>
using namespace std;

int n;
string str;

bool check(string s) {
	stack<char> st;
	for (auto c : s) {
		if (c == '(') st.push(c);
		else {
			if (st.empty()) return false;
			st.pop();
		}
	}
	return st.empty();
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		bool flag = true;
		queue<char> q;
		cin >> str;
		if(check(str)) cout << "YES\n";
		else cout << "NO\n";
	}
}