#include <bits/stdc++.h>
using namespace std;
int n;
int adj[100001];
bool vis[100001];
bool finish[100001];
int cnt;
void dfs(int cur) {
    vis[cur] = 1;
    int nxt = adj[cur];
    if(!vis[nxt]) dfs(nxt);
    else if(!finish[nxt]) {
        for(int i = nxt; i != cur; i = adj[i]) cnt++;
        cnt++;
    }
    finish[cur] = 1;
}
void dfsAll() {
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }
}
int main() {
    int tc; cin >> tc;
    while(tc--) {
        memset(vis, 0, sizeof(vis));
        memset(finish, 0, sizeof(vis));
        cnt = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> adj[i];
        dfsAll();
        cout << n - cnt << "\n";
    }
}