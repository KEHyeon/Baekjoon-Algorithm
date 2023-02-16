#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, p[10000], memo[10000][2];
vector<int> adj[10000], child[10000];
bool vis[10000];
vector<int> ans;
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
    int unPick = 0, pick = INT_MIN;
    for(int nxt : child[cur]) {
        unPick += dp(nxt, 0);
    }
    if(!pe) {
        pick = p[cur];
        for(int nxt : child[cur]) {
            pick += dp(nxt, 1);
        }
    }
    return ret = max(unPick, pick);
}
void trackAns(int cur, int pe) {
    int unPick = 0, pick = INT_MIN;
    for(int nxt : child[cur]) {
        unPick += dp(nxt, 0);
    }
    if(!pe) {
        pick = p[cur];
        for(int nxt : child[cur]) {
            pick += dp(nxt, 1);
        }
    }
    if(pick > unPick) {
        ans.push_back(cur);
        for(int nxt : child[cur]) {
            trackAns(nxt , 1);
        }
    } else {
        for(int nxt : child[cur]) {
            trackAns(nxt , 0);
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    makeTree(0);
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0) << "\n";
    trackAns(0, 0);
    sort(ans.begin(), ans.end());
    for(int i : ans) cout << i + 1 << " ";
}