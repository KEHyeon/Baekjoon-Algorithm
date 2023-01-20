#include <bits/stdc++.h>
using namespace std;
int n, p, cost[16][16];
const int MAX = 123456789;
int memo[1 << 16];
int dp(int curState) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(curState & (1 << i)) cnt++;
    }
    if(cnt >= p) return 0;
    int &ret = memo[curState];
    if(ret != -1) return ret;
    ret = 123456789;
    for(int i = 0; i < n; i++) {
        if(~curState & (1 << i)) {
            for(int j = 0; j < n; j++) {
                if(curState & (1 << j)) {
                    ret = min(ret, dp(curState | (1 << i)) + cost[j][i]);
                }
            }
        }
    }
    return ret;
}
int main() {
    memset(memo, -1, sizeof(memo));
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }
    int now = 0;
    for(int i = 0; i < n; i++) {
        char x; cin >> x;
        if(x == 'Y') {
            now |= (1 << i);
        }
    }
    cin >> p;
    if(dp(now) == MAX) cout << -1;
    else cout << dp(now);
}