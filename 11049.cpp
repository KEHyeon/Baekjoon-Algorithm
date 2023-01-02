#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
string a;
string b;
string ans;
int main() {
    cin >> a >> b;
    a = '0' + a;
    b = '0' + b;
    int alen = a.size();
    int blen = b.size();
    for(int i = 0; i < alen; i++) {
        for(int j = 0; j < blen; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if(a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    int i = alen - 1;
    int j = blen - 1;
    cout << dp[i][j] << '\n';
    while(dp[i][j] != 0) {
        if(dp[i][j] == dp[i][j-1]) j--;
        else if(dp[i][j] == dp[i-1][j]) i--;
        else {
            ans = b[j] + ans;
            i--;
            j--;
        }
    }
    cout << ans;
}