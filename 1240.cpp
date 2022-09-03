#include <bits/stdc++.h>
using namespace std;
int n, m, s, e;
vector<pair<int,int>> tree[1001];
int dis[1001];
void dfs(int cur) {
	for(auto i : tree[cur]) {
		if(dis[i.first]) continue;
		dis[i.first] = dis[cur] + i.second;
		dfs(i.first);
	}
}
int main() {
	cin >> n >> m;
	for(int i = 0; i < n - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		tree[a].push_back({b,c});
		tree[b].push_back({a,c});
		
	}
	for(int i = 0; i < m; i++) {
		cin >> s >> e;
		dis[s] = 1;
		dfs(s);
		cout << dis[e] - 1 << "\n";
		for(int i = 0; i <= n; i++) dis[i] = 0;
	}
}
