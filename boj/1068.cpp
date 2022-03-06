#include <bits/stdc++.h>
using namespace std;

int n, num;
vector<int> adj[51];
int root, target;
int ret;

int dfs(int here) {
	int ret = 0;
	int child = 0;
	for (auto there : adj[here]) {
		if (there == target) continue;
		ret+=dfs(there);
		child++;
	}
	if (child == 0) return 1;
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == -1) root = i;
		else adj[num].push_back(i);
	}
	cin >> target;
	if (target == root) {
		cout << 0;
		return 0;
	}
	cout << dfs(root);
	return 0;
}