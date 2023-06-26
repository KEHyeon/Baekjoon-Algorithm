#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a, b, c, dis[100000], INF = 100000000000000;
vector<pair<ll,ll>> graph[100000];
bool dst(ll x) {
    for(int i = 0; i < n; i++) dis[i] = INF;
    priority_queue<pair<ll,ll>> pq;
    dis[a] = 0;
    pq.push({0, a});
    while(!pq.empty()) {
        auto [sum, cur] = pq.top(); pq.pop();
        sum = -sum;
        if(cur == b) break;
        if(sum > dis[cur]) continue;
        for(auto [nxt, nxtCost] : graph[cur]) {
            if(nxtCost > x) continue;
            if(dis[nxt] <= sum + nxtCost) continue;
            dis[nxt] = sum + nxtCost;
            pq.push({-dis[nxt], nxt });
        }
    }
    return (dis[b] <= c && dis[b] != INF);
}
int main() {
    cin >> n >> m >> a >> b >> c;
    a -= 1; b -= 1;
    ll lo = 0, hi = 0;
    while(m--) {
        ll s, e, x; cin >> s >> e >> x;
        hi = max(hi, x);
        graph[s - 1].push_back({e - 1, x});
        graph[e - 1].push_back({s - 1, x});
    }
    if(!dst(hi)) {
        cout << -1;
        return 0;
    }
    while(lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if(dst(mid)) hi = mid;
        else lo = mid;
    }
    cout << lo + 1;
}