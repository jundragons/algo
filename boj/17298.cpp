#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000001];
int ret[1000001];
stack<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	memset(ret, -1, sizeof(ret));
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		while (st.size() && arr[st.top()] < arr[i]) {
			ret[st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}
	for (int i = 0; i < n; i++)
		cout << ret[i] << ' ';

}