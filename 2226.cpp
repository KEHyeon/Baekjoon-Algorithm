//#include <bits/stdc++.h>
//#define ll long long
//#define X first
//#define Y second
//#define pii pair<int,int>
//using namespace std;
//int n;
//ll dp[1001];
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cin >> n;
//    dp[1] = 0;
//    for(int i = 2; i <= n; i++) {
//        dp[i] = pow(2, i - 2) - dp[i - 1];
//    }
//    cout << dp[n];
//}
n = int(input())
dp = [0];
for i in range(1, n):
dp.append(2**(i - 1) - dp[i - 1])
print(dp[n - 1])