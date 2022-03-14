#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll st, en;
vector<pair<ll, ll>> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> st >> en;
		v.push_back({ en,st });
	}
	sort(v.begin(), v.end());
	int cur = 0;
	int ret = 0;
	for (int i = 0; i < v.size(); i++) {
		if (cur <= v[i].second) {
			cur = v[i].first;
			ret++;
		}
	}
	cout << ret;
}