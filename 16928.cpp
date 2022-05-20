#include <bits/stdc++.h>
using namespace std;
int vis[101];
int ladder[101];
int snake[101];
int n, m;
int main() {
	cin >> n >> m;
	while(n--) {
		int a, b; cin >> a >> b;
		ladder[a] = b;
	}
	while(m--) {
		int a, b; cin >> a >> b;
		snake[a] = b;
	}
	queue<int> q;
	q.push(1);
	while(!q.empty()) {
		auto cur = q.front(); q.pop();
		if(cur == 100) break;
		for(int i = 1; i <= 6; i++) {
			int nxt = cur + i;
			if(ladder[nxt]) {
				nxt = ladder[nxt];
			}
			else if(snake[nxt]) {
				nxt = snake[nxt];
			}
			if(vis[nxt]) continue;
			vis[nxt] = vis[cur] + 1;
			q.push(nxt);
		}
	}
	cout << vis[100];
}
