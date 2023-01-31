#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1000000000;
ll memo[101][10][1 << 10];
int n;
ll dp(int len, int last, int status) {
    if(len == n) {
        if(status == ((1 << 10) - 1)) return 1;
        return 0;
    }
    ll &ret = memo[len][last][status];
    if(ret != -1) return ret;
    ret = 0;
    if(last != 0) {
        ret = (ret + dp(len + 1, last - 1, status | (1 << last - 1))) % mod;
    }
    if(last != 9) {
        ret = (ret + dp(len + 1, last + 1, status | (1 << last + 1))) % mod;
    }
    return ret;
}
int main() {
    memset(memo, -1, sizeof(memo));
    cin >> n;
    ll ans = 0;
    for(int j = 1; j <= 9; j++) {
        ans = (ans + dp(1, j, (1 << j))) % mod;
    }
    cout << ans;
}