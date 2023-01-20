#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
const int mod = 1000000003;
int memo[1001][1001];
int dp(int x, int y) {
    if(y == 0) return 1;
    if(x <= 0) return 0;
    int &ret = memo[x][y];
    if(ret != -1) return ret;
    ret = (dp(x - 1, y) + dp(x - 2, y - 1)) % mod;
    return ret;
}
int main() {
    memset(memo, -1, sizeof(memo));
    cin >> n >> k;
    cout << ((dp(n - 1, k) + dp(n - 3, k - 1)) % mod);
}