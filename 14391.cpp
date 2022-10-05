#include <bits/stdc++.h>
using namespace std;
int n, m, arr[4][4], vis[4][4];

int solve() {
	int x = -1, y = -1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(vis[i][j] == 0) {
				x = i; y = j;
				i = n;
				break;
			}
		}
	}
	if(x == -1) return 0;
	int ret = -1, sum = 0;
	int cnt = 0;
	for(int i = 0; i < m; i++) {
		int ny = y + i;
		if(ny >= m || vis[x][ny]) break;
		cnt++;
		sum = sum * 10 + arr[x][ny];
		vis[x][ny] = 1;
		ret = max(ret, sum + solve());
	}
	for(int i = 0; i < cnt; i++) {
		int ny = y + i;
		vis[x][ny] = 0;
	}
	
	sum = 0, cnt = 0;
	for(int i = 0; i < n; i++) {
		int nx = x + i;
		if(nx >= n) break;
		cnt++;
		sum = sum * 10 + arr[nx][y];
		vis[nx][y] = 1;
		ret = max(ret, sum + solve());
	}
	for(int i = 0; i < cnt; i++) {
		int nx = x + i;
		vis[nx][y] = 0;
	}
	return ret;
}
int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			char x; cin >> x;
			arr[i][j] = x - '0';
		}
	}
	//ют╥б 
	cout << solve();
}
