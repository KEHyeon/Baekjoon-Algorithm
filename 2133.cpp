#include <bits/stdc++.h>
using namespace std;

int n;
int dp[31];
int main() {
    cin >> n;
    dp[0] = 1;
    dp[2] = 3;
    for(int i = 4; i <= n; i++) {
        if(i % 2) continue;
        dp[i] = dp[i - 2] * 3 + 2;
        for(int j = 2; j < i - 2; j+=2) {
            dp[i] += dp[j] * 2;
        }

    }
    cout << dp[n];
}