#include <bits/stdc++.h>
using namespace std;
int memo[19][2];
int n, k;
pair<int,int> arr[20];
int dp(int now, bool bigJump) {
    if(now >= n) return 123456789;
    if(now == n - 1) return 0;
    int &ret = memo[now][bigJump];
    if(ret) return ret;
    ret = 123456789;
    ret = min(ret, dp(now + 1, bigJump) + arr[now].first);
    ret = min(ret, dp(now + 2, bigJump) + arr[now].second);
    if(bigJump) return ret;
    return ret = min(ret, dp(now + 3, 1) + k);
}
int main() {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        arr[i] = {a, b};
    }
    cin >> k;
    cout << dp(0, 0);
}