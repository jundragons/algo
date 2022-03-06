#include <bits/stdc++.h>
using namespace std;

int graph[110][110];
int visited[110][110];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt, chess;
int n, m;
vector<pair<int, int>> v;

void go() {
	queue<pair<int, int>> q;
	vector<pair<int, int>> nv;
	for (auto i : v) {
		q.push(i);
	}
	while (q.size()) {
		auto temp = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + temp.first;
			int ny = dy[i] + temp.second;
			if (nx<1 || ny<1 || nx>n || ny>m) continue;
			if (visited[nx][ny]) continue;
			if (graph[nx][ny] == 0) {
				q.push({ nx,ny });
				visited[nx][ny] = 1;
			}
			else if (graph[nx][ny] == 1) {
				nv.push_back({ nx,ny });
				visited[nx][ny] = 1;
			}
		}
	}
	v = nv;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		v.push_back({ i,0 });
		v.push_back({ i,m+1 });
		visited[i][0] = 1;
		visited[i][m + 1] = 1;
	}
	for (int i = 0; i < m; i++) {
		v.push_back({ 0,i });
		v.push_back({ n + 1,i });
		visited[0][i] = 1;
		visited[n + 1][i] = 1;
	}

	chess = v.size();
	while (v.size()) {
		chess = v.size();
		go();
		if (v.empty()) break;
		cnt++;
	}
	cout << cnt << '\n' << chess;
}