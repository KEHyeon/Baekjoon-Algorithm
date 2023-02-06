#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int n, k;
ll sum[11];
ll memo[11][100001];
ll dp(int x, int y);
ll s(int len);
int main() {
    cin >> n >> k;
    cout << s(n);
}

ll dp(int x, int y) {
    if(x == 1) return 1;
    ll &ret = memo[x][y];
    if(ret != 0) return ret;
    ret = s(x - 1);
    ll no = 0;
    for(int i = y * 2; i <= k; i += y) {
        no = (no + dp(x - 1, i)) % mod;
    }
    ret -= no;
    if(ret < 0) ret += mod;
    return ret;
}
ll s(int len) {
    ll &ret = sum[len];
    if(ret != 0) return ret;
    for(int i = 1; i <= k; i++) {
        ret = (dp(len, i) + ret) % mod;
    }
    return ret;
}