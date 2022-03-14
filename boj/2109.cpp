#include <bits/stdc++.h>
using namespace std;
int n, cost, day, maxx, ret;
vector<pair<int, int>> v;

int used[10010];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cost >> day;
		v.push_back({ day,cost });
		maxx = max(day, maxx);
	}
	sort(v.begin(), v.end(), greater<>());
	priority_queue<int> pq;
	int cur = 0;
	for (int i = maxx; i >0; i--) {
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