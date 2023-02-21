#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n;
int memo[1001][2][3];

int dp(int day, int l, int g) {
    if(day == 1) return 1;
    int &ret = memo[day][l][g];
    if(ret != -1) return ret;
    ret = dp(day - 1, l, 0);
    if(l != 0) ret += dp(day - 1, l - 1, 0);
    if(g != 0) ret += dp(day - 1, l, g - 1);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    memset(memo, -1, sizeof(memo));
    int ans = 0;
    for(int i = 0; i <= 1; i++) {
        for(int j = 0; j <= 2; j++) {
            ans += dp(n, i, j);
        }
    }
    cout << ans;
}