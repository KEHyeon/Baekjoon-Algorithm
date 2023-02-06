#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, k, MAX;
ll ans;
multiset<ll> bag;
priority_queue<pair<int,int>> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        pq.push({b, a});
    }
    for(int i = 0; i < k; i++) {
        ll x; cin >> x;
        bag.insert(x);
    }
    while(!pq.empty() && bag.size()) {
        auto cur = pq.top(); pq.pop();
        ll value = cur.first;
        ll heavy = cur.second;
        auto it = bag.lower_bound(heavy);
        if(it != bag.end()) {
            ans += value;
            bag.erase(it);
        }
    }
    cout << ans;
}