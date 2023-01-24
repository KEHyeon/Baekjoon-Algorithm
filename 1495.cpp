#include <bits/stdc++.h>

using namespace std;

int n, s, m;
int p[50];
int memo[50][1001];
int dp(int cur, int vol) {
    if(vol > m || vol < 0) return -1;
    if(cur == n) return vol;
    int &ret = memo[cur][vol];
    if(ret != -2) return ret;
    ret = -1;
    ret = max(ret, dp(cur + 1, vol - p[cur]));
    ret = max(ret, dp(cur + 1, vol + p[cur]));
    return ret;
}

int main() {
    cin >> n >> s >> m;
    memset(memo, -2, sizeof(memo));
    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 1001; j++) memo[i][j] = -2;
    }
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    cout << dp(0, s);
}