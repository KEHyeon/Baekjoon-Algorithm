#include <bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;
map<char, pii> dir;
int n, m, memo[500][500], ans;
string arr[500];
int dp(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m) return 1;
    int &ret = memo[x][y];
    if(ret != -1) return ret;
    ret = 0;
    int nx = x + dir[arr[x][y]].X;
    int ny = y + dir[arr[x][y]].Y;
    ret = dp(nx, ny);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(memo, -1, sizeof(memo));
    dir['U'] = {-1, 0};
    dir['R'] = {0, 1};
    dir['D'] = {1, 0};
    dir['L'] = {0, -1};
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ans += dp(i, j);
        }
    }
    cout << ans;
}