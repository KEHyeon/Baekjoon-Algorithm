#include  <bits/stdc++.h>
using namespace std;
int n;
int arr[10000];
int memo[10000];
int dp(int cur) {
    if(cur == n) return 0;
    int &ret = memo[cur];
    if(ret != -1) return ret;
    int MIN = 123456789;
    int MAX = -1;
    for(int i = cur; i < n; i++) {
        if(arr[i] < MIN) MIN = arr[i];
        if(arr[i] > MAX) MAX = arr[i];
        ret = max(ret, MAX - MIN + dp(i + 1));
    }
    return ret;
}
int main() {
    for(int i = 0; i < 10000; i++) memo[i] = -1;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << dp(0);
}