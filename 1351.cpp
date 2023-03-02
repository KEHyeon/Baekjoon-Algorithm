#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
ll n, p, q;
map<ll, ll> vis;
ll dp(ll x) {
    if(x == 0) return 1;
    ll &ret = vis[x];
    if(ret != 0) return ret;
    ret = dp(x / p) + dp(x / q);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p >> q;
    cout << dp(n);
}