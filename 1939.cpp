#include <bits/stdc++.h>
#define X first
#define Y second   
using namespace std;
int n, m, s, e, lo = 1000000001, hi = -1;
vector<pair<int,int>> graph[10001];

bool check(int x) {
	bool vis[100001] = {0,};
	queue<int> Q;
	Q.push(s);
	vis[s] = 1;
	while(!Q.empty()) {
		int cur = Q.front(); Q.pop();
		for(auto nxt : graph[cur]) {
			if(nxt.Y < x || vis[nxt.X]) continue;
			vis[nxt.X] = 1;
			Q.push(nxt.X);
		}
	}
	return vis[e];
}
int main() {
	cin >> n >> m;
	while(m--) {
		int a, b, c; cin >> a >> b >> c;
		if(c < lo) lo = c;
		if(c > hi) hi = c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	hi += 1;
	cin >> s >> e;
	//ют╥б
	while(lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if(check(mid)) lo = mid;
		else hi = mid;
	}
	cout << lo;
}
