#include <bits/stdc++.h>
using namespace std;
int tc, n, goal, coin[20];
int dp[20][10001];
int solve(int start, int money) {
    if(money == 0) return 1;
    if(start == n || money < 0) return 0;
    int &ret = dp[start][money];
    if(ret != 0) return ret;
    ret = 0;
    for(int i = start; i < n; i++) {
        ret += solve(i, money - coin[i]);
    }
    return ret;
}

int main() {
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> coin[i];
        memset(dp, 0, sizeof(dp));
        cin >> goal;
        cout << solve(0, goal) << "\n";
    }
}