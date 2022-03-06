#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
	stack<char> st;
	for (auto c : s) {
		if (c == '[' || c == '(') {
			st.push(c);
		}
		else if (c == ')') {
			if (st.empty()) return false;
			if (st.top() != '(') return false;
			st.pop();
		}
		else if (c == ']') {
			if (st.empty()) return false;
			if (st.top() != '[') return false;
			st.pop();
		}
	}
	return st.empty();
}

int main() {
	while (true) {
		string str;
		getline(cin, str);
		if (str == ".") break;
		if (check(str)) cout << "yes\n";
		else cout << "no\n";
	}
}