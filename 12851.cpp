#include <bits/stdc++.h>
using namespace std;
bool vis[200001];
int n, k, ans, cnt;
int main() {
	cin >> n >> k;
	if(n == k) {
		cout << 0 << "\n" << 1;
		return 0;
	}
	queue<pair<int,int>> Q;
	Q.push({n, 0});	
	while(!Q.empty()) {
		int curx = Q.front().first;
		int time = Q.front().second;
		Q.pop();
		vis[curx] = true;
		if(!cnt && curx == k) {
			ans = time;
			cnt++;
		}
		else if(curx == k && ans == time) cnt ++;
		int nx = curx + 1;
		if(nx <= 200000 && !vis[nx]) Q.push({nx, time + 1});
		nx = curx - 1;
		if(nx >= 0 &&  nx <= 200000 && !vis[nx]) Q.push({nx, time + 1});
		nx = curx * 2;
		if(nx <= 200000 && !vis[nx]) Q.push({nx, time + 1});
	}
	cout << ans << "\n" << cnt;
}           
