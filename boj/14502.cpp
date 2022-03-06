#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[9][9];
int visited[9][9];
vector<pair<int, int>> land;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int ret;

int checked() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0 && visited[i][j]==0) cnt++;
		}
	}
	return cnt;
}

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = 1;
	while (q.size()) {
		auto temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + temp.first;
			int ny = dy[i] + temp.second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (graph[nx][ny] ==1 ||visited[nx][ny]==1) continue;
			q.push({ nx,ny });
			visited[nx][ny] = 1;
		}
	}
}

void go(int a,int b, int c) {
	graph[land[a].first][land[a].second] = 1;
	graph[land[b].first][land[b].second] = 1;
	graph[land[c].first][land[c].second] = 1;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 2 && visited[i][j] == 0) {
				bfs(i, j);
			}
		}
	}
	ret = max(ret, checked());
	graph[land[a].first][land[a].second] = 0;
	graph[land[b].first][land[b].second] = 0;
	graph[land[c].first][land[c].second] = 0;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 0) land.push_back({ i,j });
		}
	}
	for (int i = 0; i < land.size(); i++) {
		for (int j = i+1; j < land.size(); j++) {
			for (int k = j + 1; k < land.size(); k++) {
				go(i, j, k);
			}
		}
	}
	cout << ret;
}