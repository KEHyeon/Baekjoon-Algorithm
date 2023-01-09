#include <bits/stdc++.h>
using namespace std;
int n, m;
string room[12];
const int MIN = -100000;
int memo[11][1 << 10];
int dp(int line, int status) {
    if(line == n + 1) return 0;
    int &ret = memo[line][status];
    if(ret != 0) return ret;
    int cant = 0, cnt = 0;
    for(int i = 0; i < m; i++) {
        if((status &  (1 << i)) && (status & (1 << (i + 1)))) return 0;
        if(room[line + 1][i] == 'x') cant |= (1 << i); //다음 상태 처리
        if(status & (1 << i)) {
            cnt++;
            if(i - 1 >= 0) cant |= (1 << (i - 1));
            if(i + 1 <= m - 1) cant |= (1 << (i + 1));
        }
    }
    for(int nxtStatus = 0; nxtStatus < (1 << m); nxtStatus++) {
        if(nxtStatus & cant) continue;
        ret = max(ret, cnt + dp(line + 1, nxtStatus));
    }
    return ret;
}
int main() {
    int tc; cin >> tc;
    while(tc--) {
        memset(memo, 0, sizeof(memo));
        cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> room[i];
        cout << dp(0, 0) << "\n";
    }
}