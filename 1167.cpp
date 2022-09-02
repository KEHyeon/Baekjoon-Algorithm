#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> tree[100001];
int dis[100001], mx = 1;
void dfs(int cur) {
	for(auto i : tree[cur]) {
		int nxt = i.first;
		int w = i.second;
		if(dis[nxt]) continue;
		dis[nxt] = dis[cur] + w;
		if(dis[nxt] > dis[mx]) {
			mx = nxt;
		}
		dfs(nxt);
	}
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		int u; cin >> u;
		while(1) {
			int v; cin >> v;
			if(v == -1) break;
			int p; cin >> p;
			tree[u].push_back({v,p});
			tree[v].push_back({u,p});
		}
	}
	dis[1] = 1;
	dfs(1);
	for(int i = 1; i <= n; i++) dis[i] = 0;
	dis[mx] = 1;
	dfs(mx);
	cout << dis[mx] - 1;
	
}
