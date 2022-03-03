#include <bits/stdc++.h>
using namespace std;

int n;
int graph[66][66];

string go(int x, int y, int len) {
	if (len == 1) {
		return to_string(graph[x][y]);
	}
	string str = "";
	int target = graph[x][y];
	bool check = false;
	int half = len / 2;
	for (int i = x; i < x+len; i++) {
		for (int j = y; j < y+len; j++) {
			if (graph[i][j] != target) {
				str += "(";
				check = true;
				str += go(x, y, half);
				str += go(x, y + half, half);
				str += go(x + half, y, half);
				str += go(x + half, y + half, half);
				str += ")";
				break;
			}
		}
		if (check) break;
	}
	if (!check) str += to_string(graph[x][y]);
	return str;
}

int main() {
	cin >> n;
	string st;
	for (int i = 0; i < n; i++) {
		cin >> st;
		for (int j = 0; j < n; j++) {
			graph[i][j] = st[j] - '0';
		}
	}

	cout<<go(0,0,n);	
}