#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, c, t;
map<ll, pair<int, int>> mp;

bool cmp(pair<ll, pair<int, int>> a, pair<ll, pair<int, int>> b) {
	if (a.second.first == b.second.first) {
		return a.second.second < b.second.second;
	}
	return a.second.first > b.second.first;
	
}

int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> t;
		auto it = mp.find(t);
		if (it == mp.end()) {
			mp[t] = { 1,i };
		}
		else {
			mp[t].first++;
		}
	}
	vector<pair<ll, pair<int, int>>> v(mp.begin(), mp.end());
	sort(v.begin(), v.end(), cmp);

	for (auto i : v) {
		int len = i.second.first;
		while (len--) {
			cout << i.first << ' ';
		}
	}
}