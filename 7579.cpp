#include <bits/stdc++.h>
using namespace std;
int n, m, sum;
int capa[100];
int c[100];
int dp[100][10001];
int csum;
const int MIN = -1234567890;
int solve(int start, int cur) {
    if(cur < 0) return MIN;
    if(start == n) {
        if(cur == 0) return 0;
        else return MIN;
    }
    int &ret = dp[start][cur];
    if(ret != -1) return ret;
    ret = max(ret, capa[start] + solve(start + 1, cur - c[start]));
    ret = max(ret, solve(start + 1, cur));
    return ret;
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> capa[i];
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        csum += c[i];
    }
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i <= csum; i++) {
        if(solve(0, i) >= m) {
            cout << i;
            return 0;
        }
    }
}