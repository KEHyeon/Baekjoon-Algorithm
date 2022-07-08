#include <bits/stdc++.h>
using namespace std;
int n, m, g, r, sum, ans = -1234;
int garden[50][50];
bool isUsed[10];
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};
vector<pair<int,int>> two;
int bfs() {
	int rvis[50][50] = {0,};
	int gvis[50][50] = {0,};
	int cnt = 0;
	queue<pair<int,pair<int,int>>> rq;
	queue<pair<int,pair<int,int>>> gq;
	for(int i = 0; i < g + r; i++) {
		if(isUsed[i] == 1) {
			rq.push({1,two[i]});
			rvis[two[i].first][two[i].second] = 1;
		}
		else {
			gq.push({1,two[i]});
			gvis[two[i].first][two[i].second] = 1;
		}
	}
	while(!gq.empty() || !rq.empty()) {
		if(!gq.empty()) {
			auto cur = gq.front(); gq.pop();
			if(gvis[cur.second.first][cur.second.second] != -1) {
				for(int i = 0; i < 4; i++) {
					int fx = cur.second.first + dx[i];
					int fy = cur.second.second + dy[i];
					int score = cur.first;
					if(fx < 0 || fy < 0 || fx >= n || fy >= m) continue;
					if(garden[fx][fy] == 0) continue;
					if(gvis[fx][fy]) continue;
					if(rvis[fx][fy]) {
						if(rvis[fx][fy] == score + 1) {
							gvis[fx][fy] = -1;
							rvis[fx][fy] = -1;
							cnt++;
						}
						continue;
					}	
					gvis[fx][fy] = gvis[cur.second.first][cur.second.second] + 1;
					gq.push({score + 1, {fx,fy}});
				}
			}
		}
		if(!rq.empty()) {
			auto cur = rq.front(); rq.pop();
			if(rvis[cur.second.first][cur.second.second] != -1) {
				for(int i = 0; i < 4; i++) {		
					int fx = cur.second.first + dx[i];
					int fy = cur.second.second + dy[i];
					int score = cur.first;
					if(fx < 0 || fy < 0 || fx >= n || fy >= m) continue;
					if(garden[fx][fy] == 0) continue;
					if(rvis[fx][fy]) continue;
					if(gvis[fx][fy]) {
						if(gvis[fx][fy] == score + 1) {
							gvis[fx][fy] = -1;
							rvis[fx][fy] = -1;
							cnt++;
						}
						continue;
					}	
					rvis[fx][fy] = rvis[cur.second.first][cur.second.second] + 1;
					rq.push({score + 1, {fx,fy}});
				}
			}
		}
	}
	return cnt;
}
	
void bt(int num) {
	if(num == g){
		ans = max(ans,bfs());
		return;
	}
	for(int i = 0; i < two.size(); i++) {
		if(isUsed[i]) continue;
		isUsed[i] = 1;
		bt(num + 1);
		isUsed[i] = 0;
	}
}
int main() {
	cin >> n >> m >> g >> r;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> garden[i][j];
			if(garden[i][j] == 2) two.push_back({i,j});
		}
	}
	bt(0);
	cout << ans;
}
