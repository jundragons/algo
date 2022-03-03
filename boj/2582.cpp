#include <bits/stdc++.h>
using namespace std;

int n, team;
int A, B, asum, bsum;
string ti;
string bef;

string print(int num) {
	string hh = "00" + to_string(num / 60);
	string mm = "00" + to_string(num % 60);
	return hh.substr(hh.size() - 2, 2) + ":" + mm.substr(mm.size() - 2, 2);
}

int changeToInt(string t) {
	return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3));
}

void go(int& sum, string s) {
	sum += changeToInt(s) - changeToInt(bef);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> team;
		cin >> ti;
		if (A > B) go(asum, ti);
		else if (B > A) go(bsum, ti);
		team == 1 ? A++ : B++;
		bef = ti;
	}
	if (A > B) go(asum, "48:00");
	else if (B > A) go(bsum, "48:00");
	cout << print(asum) << '\n';
	cout << print(bsum) << '\n';
}