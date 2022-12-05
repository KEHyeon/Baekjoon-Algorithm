#include <bits/stdc++.h>
using namespace std;
int n;
int dp[30][40001];
int choo[30];
int solve(int start, int x) {
    if(x > 40001) return 0;
    if(start == n) return x == 0;
    int &ret = dp[start][x];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = start; i < n; i++) {
        ret = ret || solve(i + 1, x - choo[i]);
        ret = ret || solve(i + 1, x + choo[i]);
        ret = ret || solve(i + 1, x);
    }
    return ret;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> choo[i];
    int tc; cin >> tc;
    memset(dp, -1, sizeof(dp));
    while(tc--) {
        int x; cin >> x;
        cout << (solve(0, x) ? 'Y' : 'N') << " ";
    }
}