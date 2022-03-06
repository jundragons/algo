#include <bits/stdc++.h>
using namespace std;

int n, mp, mf, ms, mv;
int p, f, s, v, price;
int sp, sf, ss, sv, sprice;
int ans;
map<int, vector<vector<int>>> mpArr;

struct ingredient {
	int mp, mf, ms, mv, price;
} gre[16];

int main() {
	ans = INT_MAX;
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; i++) {
		cin >> gre[i].mp >> gre[i].mf >> gre[i].ms >> gre[i].mv >> gre[i].price;
	}
	for (int i = 1; i < (1 << n); i++) {
		sp = sf = ss = sv = sprice = 0;
		vector<int> arr;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sp += gre[j].mp;
				sf += gre[j].mf;
				ss += gre[j].ms;
				sv += gre[j].mv;
				sprice += gre[j].price;
				arr.push_back(j+1);
			}
		}
		if (sp >= mp && sf >= mf && ss >= ms && sv >= mv) {
			if (ans >= sprice) {
				ans = sprice;
				mpArr[ans].push_back(arr);
			}
		}
	}
	if (ans == INT_MAX) cout << -1;
	else {
		cout << ans << '\n';
		sort(mpArr[ans].begin(), mpArr[ans].end());
		for (auto i : mpArr[ans][0]) {
			cout << i << ' ';
		}
	}
}