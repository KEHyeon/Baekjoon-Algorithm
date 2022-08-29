#include <bits/stdc++.h>
using namespace std;
int node, cnt, n, m, ans, tc = 1;
bool vis[501];
vector<int> tree[501];
void dfs(int cur) {
	node++;
	for(auto nxt : tree[cur]) {
		cnt++;
		if(vis[nxt]) continue;
		vis[nxt] = 1;
		dfs(nxt);
	}
}
int main(){
	while(1) {
		ans = 0;
		cin >> n >> m;
		for(int i = 1; i <= n; i++) tree[i].clear();
		fill(vis, vis + n + 1, false);
		for(int i = 1; i <= n; i++) {
			vis[i] = 0;
		}
		if(n == 0 && m == 0) break;
		for(int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		for(int i = 1; i <= n; i++) {
			cnt = 0;
			node = 0;
			if(!vis[i]){
				vis[i] = 1;
				dfs(i);
				ans += (cnt / 2 == node - 1);
			}
		}
		cout << "Case " << tc++ << ": ";
		if(ans == 0) cout << "No trees.\n";
		else if(ans == 1) cout << "There is one tree.\n";
		else cout << "A forest of "<< ans << " trees.\n";
	}
}
