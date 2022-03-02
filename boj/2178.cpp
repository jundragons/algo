#include <bits/stdc++.h>
using namespace std;

int graph[101][101];
int visited[101][101];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int a, int b) {
	queue<pair<int, int >> q;
	q.push({ a,b });
	visited[a][b] = 1;
	while (!q.empty()) {
		auto temp = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + temp.first;
			int ny = dy[i] + temp.second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (graph[nx][ny] == 0 || visited[nx][ny]) continue;
			visited[nx][ny] = visited[temp.first][temp.second] + 1;
			q.push({ nx,ny });
		}
	}
}

int main() {
	cin >> n >> m;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			graph[i][j] = str[j] - '0';
		}
	}
	bfs(0, 0);
	cout << visited[n - 1][m - 1];
}