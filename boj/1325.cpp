#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector<int> adj[10010];
int visited[10010];
vector<pair<int, int>> ans;

int dfs(int here) {
	int ret = 0;
	for (auto there : adj[here]) {
		if (visited[there]) continue;
		ret += 1;
		visited[there] = 1;
		ret+=dfs(there);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		ans.push_back({ dfs(i),i });
	}
	sort(ans.begin(), ans.end(),greater<>());
	int maxx = ans[0].first;
	vector<int> ret;
	for (auto i : ans) {
		if (maxx == i.first) ret.push_back(i.second);
		else break;
	}
	sort(ret.begin(), ret.end());
	for (auto i : ret)
		cout << i << ' ';
}