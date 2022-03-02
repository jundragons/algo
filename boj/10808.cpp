#include <bits/stdc++.h>
using namespace std;
string s;
int alpha[26];

int main() {
	cin >> s;
	for (auto c : s) {
		alpha[c - 'a']++;
	}
	for (int i = 0; i < 26; i++) cout << alpha[i] << ' ';
}