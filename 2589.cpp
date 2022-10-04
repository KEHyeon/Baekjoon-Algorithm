#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, m, landlen, ans;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char map_[51][51];
vector<pair<int,int>> land;
void solve(pair<int,int> s) {
	int dis[50][50] = {0,};
	dis[s.X][s.Y] = 1;
	queue<pair<int,int>> Q;
	Q.push(s);
	while(!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for(int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(dis[nx][ny] || map_[nx][ny] != 'L') continue;
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			Q.push({nx, ny});
		}
	}
	for(auto i : land) {
		ans = max(ans, dis[i.X][i.Y] - 1);
	}
}
int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> map_[i][j];
			if(map_[i][j] == 'L') land.push_back({i, j}); 
		} 
	}
	landlen = land.size();
	for(auto i : land) {
		solve(i);
	}
	cout << ans;
}
