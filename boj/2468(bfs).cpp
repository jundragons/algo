#include <bits/stdc++.h>
using namespace std;

int n;
int graph[101][101];
int visited[101][101];
int minn=INT_MAX, maxx= INT_MIN;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int a, int b, int k) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = 1;
	while (q.size()) {
		auto temp = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + temp.first;
			int ny = dy[i] + temp.second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (graph[nx][ny] < k || visited[nx][ny]) continue;
			q.push({ nx,ny });
			visited[nx][ny] = 1;
		}
	}
}

int main() {
	int ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
			minn = min(minn, graph[i][j]);
			maxx = max(maxx, graph[i][j]);
		}
	}
	for (int k = maxx; k >= minn; k--) {
		int cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (graph[i][j] >= k && !visited[i][j]) {
					bfs(i, j, k);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;

}