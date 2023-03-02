#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n;
int c[200000];
bool vis[200000];
vector<int> adj[200000];
int dfs(int cur) {
    vis[cur] = 1;
    int ret = 0;
    for(int nxt : adj[cur]) {
        if(vis[nxt]) continue;
        ret += (c[cur] != c[nxt]);
        ret += dfs(nxt);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int root = -1;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        if(c[i] == 0) root = i;
    }
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    cout << dfs(0) + (root == -1);
}