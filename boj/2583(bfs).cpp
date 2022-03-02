#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int graph[105][105];
int visited[105][105];
int a, b, c, d;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int> v;

int bfs(int a, int b) {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ a,b });
	visited[a][b] = 1;
	while (q.size()) {
		auto temp = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + temp.first;
			int ny = dy[i] + temp.second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (graph[nx][ny] == 1 || visited[nx][ny]) continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
			cnt++;
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m >> k;
	for (int l = 0; l < k; l++) {
		cin >> a >> b >> c >> d;
		for (int i = b; i < d; i++) {
			for (int j = a; j < c; j++) {
				graph[i][j] = 1;
			}
		}	
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!graph[i][j]&& !visited[i][j]) {
				v.push_back(bfs(i, j));
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (auto i : v)
		cout << i << ' ';
}