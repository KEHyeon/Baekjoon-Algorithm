#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n;
vector<int> adj[1000000];
vector<int> child[1000000];
bool vis[1000000];
int memo[1000000][2];
void makeTree(int cur) {
    vis[cur] = 1;
    for(int nxt : adj[cur]) {
        if(vis[nxt]) continue;
        child[cur].push_back(nxt);
        makeTree(nxt);
    }
}
int dp(int cur, int pe) {
    int &ret = memo[cur][pe];
    if(ret != -1) return ret;
    int pick = 1;
    for(int nxt : child[cur]) pick += dp(nxt, 1);
    int unPick = INT_MAX;
    if(pe) {
        unPick = 0;
        for(int nxt : child[cur]) unPick += dp(nxt, 0);
    }
    return ret = min(pick, unPick);
}
int main(void_t<>) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    makeTree(0);
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 1);
}