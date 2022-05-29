#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[1000];
int arr[1000];
int ans;
int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = i - 1; j >= 0; j--) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if(ans < dp[i]) ans = dp[i];
    }
    cout << n - ans;
}

