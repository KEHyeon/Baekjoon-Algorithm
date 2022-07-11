#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
int dp[1000001][1000001];
int n, m;
bool f(int s, int e) {
	if(s > e || s == e) return 1;
	if(dp[s][e] != -1) return dp[s][e]; 
	return dp[s][e] = (arr[s] == arr[e]) && f(s + 1, e - 1);
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			dp[i][j] = -1;
		}
	}
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	while(m--) {
		int s, e; cin >> s >> e;
		cout << f(s,e) << '\n';
	}
}
