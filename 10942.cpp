#include <bits/stdc++.h>
using namespace std;
int arr[2001];
int n, m;
bool f(int s, int e) {
	if(s > e || s == e) return 1;
	return (arr[s] == arr[e]) && f(s + 1, e - 1);
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	while(m--) {
		int s, e; cin >> s >> e;
		cout << f(s,e) << '\n';
	}
}
