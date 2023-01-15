#include <bits/stdc++.h>
using namespace std;
long long int memo[20000];
long long int arr[20000];
int n, m, k;
long long dp(int cur) {
    if(cur == n) return 0;
    long long int &ret = memo[cur];
    if(ret != -1) return ret;
    long long int MIN = INT_MAX;
    long long int MAX = -1;
    ret = LONG_LONG_MAX;
    long long int cnt = 1;
    for(int i = cur; i < cur + m && i < n; i++) {
        if(arr[i] > MAX) MAX = arr[i];
        if(arr[i] < MIN) MIN = arr[i];
        cnt = 1 + m  - (cur + m - i);
        ret = min(ret, dp(i + 1) + k + cnt * (MAX - MIN));
        cnt++;
    }
    return ret;
}
int main() {
    memset(memo, -1, sizeof(memo));
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << dp(0);
}