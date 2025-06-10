#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cstring>
using namespace std;

long long n, a, b, c, ans;
long long dp[100001][16][16];
long long solve(int score, int white, int black) {
    if(white == 0 && black == 0) {
        if(score > ans) {
            ans = score;
        }
        return 0;
    }
    long long &ret =  dp[score][white][black];
    if (ret != -1) return ret;

    ret = 0;
    if(white > 0) {
        ret = ret + solve((score + b) % 100000, white - 1, black);
    }

    if(white < black){
        ret =  max(ret, ret + solve((score * c) % 100000, white, black- 1));
    }
    return ret;
}
int main() {
    cin >> n >> a >> b >> c;
    memset(dp, -1, sizeof(dp));
    solve(a, n, n);
    cout << ans;
}