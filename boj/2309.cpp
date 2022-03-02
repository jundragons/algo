#include <bits/stdc++.h>
using namespace std;
int v[9];

int main() {
	for (int i = 0; i < 9; i++) cin >> v[i];
	sort(v, v + 9);
	do {
		int sum = 0;
		for (int i = 0; i < 7; i++) sum += v[i];
		if (sum == 100) break;
	} while (next_permutation(v, v + 9));
	for (int i = 0; i < 7; i++) cout << v[i] << '\n';
}