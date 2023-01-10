#include <bits/stdc++.h>
using namespace std;
int memo[3001][3001];
int s, len;
string str;
const int mod = 1000000007;
int solve(int x, int y) {
    if(y == 0) return 1;
    if(x == len) return 0;
    int &ret = memo[x][y];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i <= 25; i++) {
        if(y - i < 0) break;
        ret += solve(x + 1,y - i);
        ret %= mod;
    }
    return ret;
}
int main() {
    memset(memo, -1, sizeof(memo));
    cin >> s >> str;
    len = str.size();
    cout << solve(0, s);
}