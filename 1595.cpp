#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n;
vector<pii> adj[10000];
ll d[10000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, c;
    while(cin >> a >> b >> c) {
        adj[a - 1].push_back({b - 1, c});
        adj[b - 1].push_back({a - 1, c});
    }
    queue<int> Q; Q.push(0); d[0] = 0;
    ll md = -1, t;
    memset(d, -1, sizeof(d));
    while(!Q.empty()) {
        ll cur = Q.front(); Q.pop();
        for(auto [nxt, cost] : adj[cur]) {
            if(d[nxt] != -1) continue;
            d[nxt] = d[cur] + cost;
            if(md < d[nxt]) {
                md = d[nxt];
                t = nxt;
            }
            Q.push(nxt);
        }
    }
    Q.push(t);
    memset(d, -1, sizeof(d));
    d[t] = 0;
    ll ans = 0;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(auto [nxt, cost] : adj[cur]) {
            if(d[nxt] != -1) continue;
            d[nxt] = d[cur] + cost;
            ans = max(ans, d[nxt]);
            Q.push(nxt);
        }
    }
    cout << ans;
}