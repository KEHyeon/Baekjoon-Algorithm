#include <bits/stdc++.h>
using namespace std;
int arr[2001];
int dp[2001][2001];
int n, m;
bool f(int s, int e) {
	if(dp[s][e] != -1) return dp[s][e];
	if(s == e) return dp[s][e] = 1;
	if(e - s  + 1 == 2) {
		return dp[s][e] = (arr[e] == arr[s]);
	}
	if(e - s  + 1 == 3) {
		return dp[s][e] = (arr[e] == arr[s]);
	}
	int mid = (e + s) / 2;
	if((e - s + 1) % 2) {
		if(arr[mid - 1] != arr[mid + 1]) return dp[s][e] = 0;
		return dp[s][e] = (f(s,mid - 2) && f(mid + 2,e));
	}
	else {
		if(arr[mid] != arr[mid + 1] ) return dp[s][e] = 0;
		return dp[s][e] = (f(s,mid - 1) && f(mid + 2,e));
	}
	
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
