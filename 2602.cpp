#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
string pt, str[2];
int memo[20][100][2], n;
int dp(int x, int y, bool z) {
    if(x == pt.size() - 1) return 1;
    int &ret = memo[x][y][z];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = y + 1; i < n; i++) {
        if(str[!z][i] == pt[x + 1]) {
            ret += dp(x + 1, i, !z);
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> pt >> str[0] >> str[1];
    n = str[0].size();
    int ans = 0;
    memset(memo, -1, sizeof(memo));
    for(int i = 0; i < n; i++) {
        if(str[0][i] == pt[0]) {
            ans += dp(0, i, 0);
        }
        if(str[1][i] == pt[0]) ans += dp(0, i, 1);
    }
    cout << ans;
}