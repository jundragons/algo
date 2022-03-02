#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int graph[51][51];
int visited[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = 1;
	while (q.size()) {
		auto temp = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + temp.first;
			int ny = dy[i] + temp.second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (graph[nx][ny] == 0 || visited[nx][ny]) continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}
int main() {
	int n_test;
	cin >> n_test;
	while (n_test--) {
		int ans = 0;
		memset(graph, 0, sizeof(graph));
		memset(visited, 0, sizeof(visited));
		cin >> m >> n >> k;
		while (k--) {
			int a, b;
			cin >> a >> b;
			graph[a][b] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (graph[i][j] && !visited[i][j]) {
					bfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}