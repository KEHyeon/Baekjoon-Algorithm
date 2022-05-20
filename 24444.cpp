#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100001];
int ans[100001];
int n, m, r, cnt = 1;
void bfs(int s) {
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		for(auto nxt : graph[cur]) {
			if(ans[nxt]) continue;
			ans[nxt] = cnt++;
			q.push(nxt);
		}
	}
}
int main() {
	cin >> n >> m >> r;
	while(m--) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());
	ans[r] = cnt++;
	bfs(r);
	for(int i = 1; i <= n; i++) cout << ans[i] << "\n";
}
