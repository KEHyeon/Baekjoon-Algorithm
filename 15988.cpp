#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000009;
int dp[1000001] = {0,1, 2, 4};
int main() {
    for(int i = 4; i <= 1000000; i++) {
        dp[i] = ((dp[i - 1] + dp[i - 2]) % mod + dp[i - 3]) % mod;
    }
    int tc; cin >> tc;
    while(tc--) {
        int x; cin >> x;
        cout << dp[x] << "\n";
    }
}