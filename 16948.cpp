#include <bits/stdc++.h>
using namespace std;
int r, c, sheep, wolf, o, v;
queue<pair<int,int>> q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0, 1, 0, -1};
bool vis[250][250];
char md[250][250];
int main() {
	cin >> r >> c;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cin >> md[i][j];
			if(md[i][j] == '#') vis[i][j] = 1;
		}
	}
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			o = 0; v = 0;
			if(vis[i][j]) continue;
			vis[i][j] = 1;
			q.push({i,j});
			if(md[i][j] == 'v') v++;
			else if(md[i][j] == 'o') o++;
			while(!q.empty()) {
				auto cur = q.front(); q.pop();
				for(int i = 0; i < 4; i++) {
					int fx = cur.first + dx[i];
					int fy = cur.second + dy[i];
					if(fx < 0 || fy < 0 || fx >= r || fy >= c) continue;
					if(vis[fx][fy]) continue;
					if(md[fx][fy] == 'v') v++;
					else if(md[fx][fy] == 'o') o++;
					vis[fx][fy] = 1;
					q.push({fx, fy});
				}
			}
			if(o > v) sheep += o;
			else wolf += v;	
		}
	}
	cout << sheep << ' ' << wolf;
}
