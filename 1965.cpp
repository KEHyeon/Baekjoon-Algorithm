#include <bits/stdc++.h>
using namespace std;
int n, ans;
int arr[1000];
int dp[1000];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += 1;
        ans = max(ans, dp[i]);
    }
    cout << ans;
}