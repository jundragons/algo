#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	while (true) {
		cin >> str;
		if (str == "end") break;
		bool flag = true;
		int vcnt = 0, ccnt = 0;
		int vlen = 0, clen = 0;
		for (int i = 0; i < str.size(); i++) {
			if (i > 0 && str[i] == str[i - 1]) {
				if (str[i] != 'e' && str[i] != 'o') {
					flag = false;
					break;
				}
			}
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
				vcnt++;
				vlen++;
				if (vlen == 3) {
					flag = false;
					break;
				}
				clen = 0;
			}
			else {
				ccnt++;
				clen++;
				if (clen == 3) {
					flag = false;
					break;
				}
				vlen = 0;
			}
		}
		if (vcnt == 0) flag = false;
		cout << "<" << str << "> is ";
		if (!flag) cout << "not ";
		cout << "acceptable.\n";
	}
}