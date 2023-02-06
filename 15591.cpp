#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n, q;
vector<pii> adj[5001];
int dist[5001];
int main() {
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    while(q--) {
        int k, v; cin >> k >> v;
        for(int i = 0; i < 5001; i++) dist[i] = 123456789;
        queue<int> q; q.push(v);
        dist[v] = 123456780;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto [nxt, usado] : adj[cur]) {
                if(dist[nxt] != 123456789) continue;
                dist[nxt] = min(dist[cur], usado);
                q.push(nxt);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(i == v) continue;
            if(dist[i] >= k) ans++;
        }
        cout << ans << '\n';
    }
}