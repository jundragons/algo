#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans[102][102];
string s;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'c') ans[i][j] = 0;
			else ans[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		int j = 0;
		for (; j < m; j++) {
			if (ans[i][j] == 0) {
				int cnt = 1;
				while (ans[i][j + 1] == -1) {
					ans[i][j + 1] = cnt;
					cnt++;
					j++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}