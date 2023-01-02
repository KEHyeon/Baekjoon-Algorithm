#include <bits/stdc++.h>
using namespace std;
int dp[41];
int vip[41];
int n, m;
int main() {
    cin >> n >> m;
    while(m--) {
        int x; cin >> x;
        vip[x] = 1;
    }
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(vip[i] || vip[i - 1]) dp[i] = dp[i - 1];
        else dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}