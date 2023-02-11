#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, m;
pii candy[5000];
int memo[10001];
int dp(int mo) {
    if(mo < 0) return -123456789;
    int &ret = memo[mo];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < n; i++) {
        ret = max(dp(mo - candy[i].Y) + candy[i].X, dp(mo));
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(1) {
        double x;
        cin >> n >> x;
        if(n == 0) break;
        m = static_cast<int>(x * 100.0 + 0.5);
        memset(memo, -1, sizeof(memo));
        for(int i = 0; i < n; i++) {
            int a; double b; cin >> a >> b;
            candy[i] = {a, static_cast<int>(b * 100.0 + 0.5)};
        }
        cout << dp(m) << "\n";
    }
}