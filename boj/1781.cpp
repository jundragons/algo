#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, cup, day, maxx;
ll ret;
vector<pair<int, int>> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> day >> cup;
		v.push_back({ day,cup });
		maxx = max(day, maxx);
	}
	sort(v.begin(), v.end(), greater<>());
	priority_queue<int> pq;
	int cur = 0;
	for (int i = maxx; i > 0; i--) {
		while (cur < v.size() && v[cur].first == i) {
			pq.push(v[cur++].second);
		}
		if (pq.size()) {
			ret += pq.top();
			pq.pop();
		}
	}
	cout << ret;
}