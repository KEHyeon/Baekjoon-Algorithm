#include  <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, ans;
const int mod = 1e9 + 7;
vector<int> graph[100001];
ll memo[100001][8];

ll dp(int x, int len) {
    if(len == 7) return 1;
    ll &ret = memo[x][len];
    if(ret != -1) return ret;
    ret = 0;
    for(int nxt : graph[x]) {
        ret = (ret + dp(nxt, len + 1)) % mod;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(memo, -1, sizeof(memo));
    cin >> n >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        ans = (ans + dp(i, 0)) % mod;
    }
    cout << ans;
}