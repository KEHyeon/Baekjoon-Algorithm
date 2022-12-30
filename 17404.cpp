#include <bits/stdc++.h>
using namespace std;
int n, arr[1000][3];
int memo[3][3][1000];
const int MAX = 123456789;
int dp(int s, int c, int num) {
    if(num == n - 1) {
        if(s == c) return MAX;
        return arr[num][c];
    }
    int &ret = memo[s][c][num];
    if(ret != 0) return ret;
    ret = MAX;
    if(c != 0) ret = min(ret, dp(s, 0, num + 1) + arr[num][c]);
    if(c != 1) ret = min(ret, dp(s, 1, num + 1) + arr[num][c]);
    if(c != 2) ret = min(ret, dp(s, 2, num + 1) + arr[num][c]);
    return ret;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i][0];
        cin >> arr[i][1];
        cin >> arr[i][2];
    }
    int ans = MAX;
    for(int i = 0; i < 3; i++) {
        ans = min(ans, dp(i, i, 0));
    }
    cout << ans;
}