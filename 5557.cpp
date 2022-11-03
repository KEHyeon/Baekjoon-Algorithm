#include <bits/stdc++.h>
using namespace std;
int k, num[100];
long long int memo[100][21];
long long int dp(int n, int m) {
    if(m < 0 || m > 20) return 0;
    if(n == 0) {
        if(m == num[0]) return 1;
        else return 0;
    }
    long long int &ret = memo[n][m];
    if(ret != -1) return ret;
    return ret = dp(n - 1, m - num[n]) + dp(n - 1, m + num[n]);
}
int main() {
    memset(memo, -1, sizeof(memo));
    cin >> k;
    for(int i = 0; i < k; i++) cin >> num[i];
    cout << dp(k - 2, num[k - 1]);
}