#include <bits/stdc++.h>
using namespace std;
__uint128_t memo[101][101];
int n, m;
__uint128_t combi(int x, int y) {
    if(y == 0 || y == x) return 1;
    __uint128_t &ret = memo[x][y];
    if(ret) return ret;
    ret = combi(x -1, y - 1) + combi(x-1,y);
    return ret;
}
int main() {
    cin >> n >> m;
    printf("%lld%016lld", dp2[n][m], dp[n][m]);
}