#include <bits/stdc++.h>
using namespace std;
long long int n, l, r;
long long int memo[101][101][101];
const long long int mod = 1000000007;
long long int solve(int h, int left, int right) {
    if(h == 1 && left == 1 && right == 1) return 1;
    if(left == 0 || right == 0) return 0;
    if(h == 0) return 0;
    long long int &ret = memo[h][left][right];
    if(ret != -1) return ret;
    ret = 0;
    ret = (ret + (solve(h - 1, left, right) * (h - 2)) % mod) % mod;
    ret = (ret + solve(h - 1, left - 1, right)) % mod;
    ret = (ret + solve(h - 1, left, right - 1)) % mod;
    return ret % mod;

}
int main() {
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            for(int k = 0; k < 101; k++) {
                memo[i][j][k] = -1;
            }
        }
    }
    cin >> n >> l >> r;
    cout << solve(n, l, r);
}