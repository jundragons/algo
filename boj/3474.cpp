#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n_test;
ll num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n_test;
	for (int i = 0; i < n_test; i++) {
		cin >> num;
		int twoCnt = 0;
		int fiveCnt = 0;
		for (int j = 2; j <= num; j *= 2) {
			twoCnt += num / j;
		}
		for (int j = 5; j <= num; j *= 5) {
			fiveCnt += num / j;
		}
		cout << min(twoCnt, fiveCnt) << '\n';
	}
}