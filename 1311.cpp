#include <bits/stdc++.h>
using namespace std;
int n, d[20][20], memo[20][(1 << 20) - 2];
const int INF = 1000000000;
int dp(int p, int status) {
    if(status == ((1 << n) - 1)) return 0;
    if(p == n) return INF;
    int &ret = memo[p][status];
    if(ret != -1) return ret;
    ret = INF;
    for(int i = 0; i < n; i++) {
        if(status & (1 << i)) continue;
        ret = min(ret,  dp(p + 1, status | (1 << i)) + d[p][i]);
    }
    return ret;
}
int main() {
    memset(memo, -1, sizeof(memo));
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
    dp(0, 0);
    cout << memo[0][0];
}