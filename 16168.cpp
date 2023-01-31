#include <bits/stdc++.h>
using namespace std;
int v, e;
vector<int> adj[3001];
bool vis[3001];
bool dfs(int cur, int dist) {
    if(dist == v - 1) {
        cout << cur << " ";
        for(int i : adj[cur]) {
            if(i == 1) return 1;
        }
    }
    bool ret = 0;
    for(int nxt : adj[cur]) {
        if(vis[nxt]) continue;
        vis[nxt] = 1;
        ret |= dfs(nxt, dist + 1);
        vis[nxt] = 0;
    }
    return ret;
}
int main() {
    cin >> v >> e;
    while(e--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vis[1] = 1;
    if(dfs(1, 0)) cout << "YES";
    else cout << "NO";
}