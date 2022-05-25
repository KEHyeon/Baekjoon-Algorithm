#include <bits/stdc++.h>
using namespace std;

int n, cnt, ans, level = 2;
pair<int,int> baby;
int arr[20][20];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void levelUp() {
	cnt++;
	if(cnt == level) {
		level++;
		cnt = 0;
	}
}
vector<vector<int>> bfs(int x, int y) {
	vector<vector<int>> dist(20, vector<int>(20, 0));
	bool vis[20][20] = {0,};
	queue<pair<int,int>> q;
	q.push({x,y});
	vis[x][y] = 1;
	while(!q.empty()) {
		auto cur = q.front(); q.pop();
		for(int i = 0; i < 4; i++) {
			int fx = cur.first + dx[i];
			int fy = cur.second + dy[i];
			if(fx >= n || fy >= n || fx < 0 || fy < 0) continue;
			if(vis[fx][fy]) continue;
			if(arr[fx][fy] > level) continue;
			dist[fx][fy] = dist[cur.first][cur.second] + 1;
			vis[fx][fy] = 1;
			q.push({fx, fy});
		}
	}
	return dist;
}

int choice(vector<vector<int>> dist) {
	int min = 1000000000;
	pair<int,int> food;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) { 
			if(arr[i][j] != 0 && dist[i][j] && min > dist[i][j] && level > arr[i][j]) {
				min = dist[i][j];
				food = {i,j};
			}
		}
	}
	if(min == 1000000000) return 0;
	arr[food.first][food.second] = 0;
	baby = food;
	levelUp();
	return min;
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if(arr[i][j] == 9) {
				arr[i][j] = 0;
				baby.first = i;
				baby.second = j;
			}
		}
	}
	while(1) {
		vector<vector<int>> dist = bfs(baby.first, baby.second);
		int temp = choice(dist);
		if(temp == 0) break;
		ans += temp;
	}
	cout << ans;
}
