#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
string n;
ll dp[41];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    n = '7' + n;
    dp[0] = 1;
    for(int i = 1; i < n.size(); i++) {
        if(n[i] != '0') dp[i] = dp[i - 1];
        if((n[i - 1] - '0') * 10 + n[i] - '0' <= 34 && n[i - 1] != '0') {
            dp[i] += dp[i - 2];
        }
    }
    cout << dp[n.size() - 1];
}
