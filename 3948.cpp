#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, m;
vector<int> bg[200], sm[200];
bool vis1[200], vis2[200];
int dfs1(int cur) {
    vis1[cur] = 1;
    int ret = 0;
    for(int nxt : bg[cur]) {
        if(vis1[nxt]) continue;
        ret += dfs1(nxt);
    }
    return ret + 1;
}
int dfs2(int cur) {
    vis2[cur] = 1;
    int ret = 0;
    for(int nxt : sm[cur]) {
        if(vis2[nxt]) continue;
        ret += dfs2(nxt);
    }
    return ret + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        sm[a - 1].push_back(b - 1);
        bg[b - 1].push_back(a - 1);
    }
    for(int i = 0; i < n; i++) {
        memset(vis1, 0, sizeof(vis1));
        memset(vis2, 0, sizeof(vis2));
        cout << n - dfs1(i) - dfs2(i) + 1 << "\n";
    }
}