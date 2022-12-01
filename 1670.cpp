#include <bits/stdc++.h>
using namespace std;
int n;
const int mod = 987654321;
int memo[5001][5001];
int solve(int one, int half) {
    if(one == 0) return 1;
    int &ret = memo[one][half];
    if(ret != 0) return ret;
    ret += solve(one - 1, half + 1);
    ret += half != 0 ? solve(one, half - 1) : 0;
    ret = ret % mod;
    return ret;
}
int main() {
    cin >> n;
    cout << solve(n / 2, 0);
}