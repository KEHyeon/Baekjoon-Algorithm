#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1001];
int memo[1001][1001];
int dp(int start, int num) {
    if(num == 0) return 0;
    if(num < 0) return 12345678;
    if(start > n) return 12345678;
    int &ret = memo[start][num];
    if(ret != -1) return ret;
    ret = 123456789;
    ret = min(ret, arr[start] + dp(start, num - start));
    ret = min(ret, arr[start] + dp(start + 1, num - start));
    ret = min(ret, dp(start + 1, num));
    return ret;
}
int main() {
    cin >> n;
    memset(memo, -1, sizeof(memo));
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cout << dp(1, n);
}