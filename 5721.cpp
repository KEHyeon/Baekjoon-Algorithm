#include <bits/stdc++.h>
using namespace std;
int row[100000], dp[100000], n, m, arr[100000];
int rowdp(int c) {
    if(c >= m) return 0;
    int &ret = dp[c];
    if(ret != 0) return ret;
    return ret = max(arr[c] + rowdp(c + 2), rowdp(c + 1));
}
int dp2(int num) {
    if(num >= n) return 0;
    int &ret = dp[num];
    if(ret != 0) return ret;
    return ret = max(row[num] + dp2(num + 2), dp2(num + 1));
}
int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);
    while(1) {
        cin >> n >> m;
        if(m == 0) return 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 100000; j++) {
                dp[j] = 0;
            }
            for(int j = 0; j < m; j++) {
                dp[j] = 0;
                cin >> arr[j];
            }
            rowdp(0);
            row[i] = dp[0];
        }
        memset(dp, 0, sizeof(dp));
        cout << dp2(0) << "\n";
    }
}