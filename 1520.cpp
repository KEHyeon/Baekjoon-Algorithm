#include <bits/stdc++.h>
using namespace std;
int n, m, arr[500][500], memo[500][500];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dp(int x, int y) {
    if(x == 0 && y == 0) return 1;
    int &ret = memo[x][y];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(arr[x][y] >= arr[nx][ny]) continue;
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        ret += dp(nx, ny);
    }
    return ret;
}

int main() {
    memset(memo, -1, sizeof(memo));
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    cout << dp(n - 1, m - 1);
}