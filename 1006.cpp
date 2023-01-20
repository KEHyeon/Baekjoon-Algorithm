#include <bits/stdc++.h>
using namespace std;
int dp[10001][10001], out[10001], in[10001];
int n, w;

int f(int x, int y) {
    if(x == -1) return 0;
    if(y == -1) return 0;
    if(x == 0 && y == 0) return 0;
    int &ret = dp[x][y];
    if(ret != 0) return ret;
    if(x > 0) ret = max(ret, f(x - 1, y) + 1);
    if(y > 0) ret = max(ret, f(x, y - 1) + 1);
    if(in[x] + out[y] <= w && x == y) ret = max(ret, f(x - 1, y - 1) + 1);
    if(in[x] + in[x - 1] <= w && x >= 1) ret = max(ret, f(x - 2, y) + 1);
    if(out[y] + out[y - 1] <= w && y >= 1)ret = max(ret, f(x, y - 2) + 1);
    return ret;
}
int main() {
    int tc; cin >> tc;
    while(tc--) {
        memset(dp, 0, sizeof(dp));
        cin >> n >> w;
        for(int i = 1; i <= n; i++) cin >> in[i];
        in[0] = in[n];
        for(int i = 1; i <= n; i++) cin >> out[i];
        out[0] = out[n];
        cout << f(n, n) << "\n";
    }
}