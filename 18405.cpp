#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int arr[200][200];
int dis[200][200];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int n, k, s, x, y;

int main() {
	cin >> n >> k;
	queue< pair<int, int> > Q;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if(arr[i][j]) Q.push({i, j});
		}
	}
	cin >> s >> x >> y;
	while(!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		int color = arr[cur.X][cur.Y];
		if(dis[cur.X][cur.Y] == s) continue;
		for(int i = 0; i < 4; i++) {
			int fx = cur.first + dx[i];
			int fy = cur.second + dy[i];
			if(fx < 0 || fy < 0 || fx >= n || fy >= n) continue;
			if(arr[fx][fy]) {
				if(dis[fx][fy] && dis[fx][fy]  == dis[cur.X][cur.Y] + 1) {
					arr[fx][fy] = min(color, arr[fx][fy]);
				}
				continue;
			}
			arr[fx][fy] = color;
			dis[fx][fy] = dis[cur.X][cur.Y] + 1;
			Q.push({fx,fy});
		}
	}
	cout << arr[x - 1][y - 1];
}
