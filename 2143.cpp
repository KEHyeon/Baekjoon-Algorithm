#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t, n, m, ans;
ll asum[1001];
ll bsum[1001];
vector<ll> aa;
vector<ll> bb;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        asum[i] = asum[i - 1] + x;
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int x; cin >> x;
        bsum[i] = bsum[i - 1] + x;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            aa.push_back(asum[j] - asum[i - 1]);
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = i; j <= m; j++) {
            bb.push_back(bsum[j] - bsum[i - 1]);
        }
    }
    sort(bb.begin(), bb.end());
    for(ll a : aa) {
        ans += upper_bound(bb.begin(), bb.end(), t - a) - lower_bound(bb.begin(), bb.end(), t - a);
    }
    cout << ans;
}