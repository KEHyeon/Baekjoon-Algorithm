#include <bits/stdc++.h>
using namespace std;
int n, m, w, b;
char arr[100][100];
bool vis[100][100];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(vis[i][j]) continue;
			char team = arr[i][j];
			int cnt = 1;
			vis[i][j] = 1;
			queue<pair<int,int>> q;
			q.push({i,j});
			while(!q.empty()) {
				auto cur = q.front(); q.pop();
				for(int k = 0; k < 4; k++) {
					int fx = cur.first + dx[k];
					int fy = cur.second + dy[k];
					if(fx < 0 || fy < 0 || fx >= m || fy >= n) continue;
					if(vis[fx][fy] || arr[fx][fy] != team) continue;
					cnt++;
					vis[fx][fy] = 1;
					q.push({fx,fy});
				}
			}
			if(team == 'B') b += cnt * cnt;
			else w += cnt * cnt;
		}
	}
	cout << w << ' ' << b;
}
