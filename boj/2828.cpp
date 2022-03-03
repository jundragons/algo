#include <bits/stdc++.h>
using namespace std;

int n, m, k, apple, cnt;

int main() {
	cin >> n >> m >> k;
	int start = 1;
	for (int i = 0; i < k; i++) {
		cin >> apple;
		if (apple >= start && apple <= m) continue;
		else if (apple > m) {
			cnt += apple - m;
			start += apple - m;
			m = apple;
		}
		else {
			cnt += start - apple;
			m -= start - apple;
			start = apple;
		}
	}
	cout << cnt;
}