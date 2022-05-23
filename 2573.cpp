#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int arr[300][300];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int bfs() {
	int cnt = 0;
	int vis[300][300] = {0,};
	queue<pair<int,int>> q;
	for(int i = 1; i < n - 1; i++) {
		for(int j = 1; j < m - 1; j++) {
			if(arr[i][j] != -1 && vis[i][j] == 0) {
				cnt++;
				q.push({i,j});
				vis[i][j] = 1;
				while(!q.empty()) {
					auto cur = q.front(); q.pop();
					for(int k = 0; k < 4; k++) {
						int fx = cur.first + dx[k];
						int fy = cur.second + dy[k];
						if(fx < 0 || fy < 0 || fx >= n || fy >= m || vis[fx][fy]) continue;
						if(arr[fx][fy] == -1) continue;
						vis[fx][fy] = 1;
						q.push({fx,fy});
					}
				}
			}
		}
	}
	return cnt;
}
void melt() {
	queue<pair<int,int>> zero;
	for(int i = 1; i < n - 1; i++) {
		for(int j = 1; j < m - 1; j++) {
			if(arr[i][j] != -1) {
				for(int k = 0; k < 4; k++) {
					if(arr[i + dx[k]][j + dy[k]] == -1) {
						arr[i][j]--;
						if(arr[i][j] == 0) {
							zero.push({i, j});
							break;
						}
					}
				}
			}
		}
	}
	while(!zero.empty()) {
		auto cur = zero.front(); zero.pop();
		arr[cur.first][cur.second] = -1;
	}
}
int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if(arr[i][j] == 0) arr[i][j] = -1;
		}
	}
	while(bfs() == 1) {
		ans++;
		melt();
	}
	cout << ans;
}
