#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
using namespace std;
ll dist1[100001], dist2[100001], n, m, s, e;
bool vis[100001];
vector<pii> adj[100001];
void di(ll st, ll *dist) {
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= n; i++) {
        dist[i] = LONG_LONG_MAX;
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, st});
    dist[st] = 0;
    while(!pq.empty()) {
        ll cur;
        do{
            cur = pq.top().Y; pq.pop();
        }while(!pq.empty() && vis[cur]);
        if(vis[cur]) break;
        vis[cur] = 1;
        for(auto nxt : adj[cur]) {
            if(dist[nxt.Y] > dist[cur] + nxt.X) {
                dist[nxt.Y] = dist[cur] + nxt.X;
                pq.push({dist[nxt.Y], nxt.Y});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while(m--) {
        ll a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    cin >> s >> e;
    di(s, dist1);
    di(e, dist2);
    ll p; cin >> p;
    ll ans = LONG_LONG_MAX;
    while(p--) {
        int x; cin >> x;
        if(dist1[x] != LONG_LONG_MAX && dist2[x] != LONG_LONG_MAX) {
            ans = min(dist1[x] + dist2[x], ans);
        }
    }
    if(ans == LONG_LONG_MAX) cout << -1;
    else cout << ans;
}