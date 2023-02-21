#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, s;
vector<pii> p;
ll memo[300000];
ll dp(int x) {
    if(x == n) return 0;
    ll &ret = memo[x];
    if(ret != -1) return ret;
    ret = 0;
    int nxt = lower_bound(p.begin(), p.end(), make_pair(p[x].X + s, 0)) - p.begin();
    ret = max(dp(nxt) + p[x].Y, dp(x + 1));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        p.push_back({a, b});
    }
    sort(p.begin(), p.end());
    memset(memo, -1, sizeof(memo));
    cout << dp(0);
}