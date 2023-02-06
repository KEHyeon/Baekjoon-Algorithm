#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
vector<int> adj[200001];
bool vis[200001];
void dfs(int cur) {
    vis[cur] = 1;
    int nxt = adj[cur].back();
}
void dfsAll() {
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
            ans++;
        }
    }
}
int main() {
    cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    dfsAll();
    cout << ans;
}