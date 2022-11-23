#include <bits/stdc++.h>
using namespace std;
int n, arr[500][500], memo[500][500], ans;
int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};
int dfs(int x, int y) {
    int &ret = memo[x][y];
    if(ret != -1) return ret;
    ret = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(arr[x][y] >= arr[nx][ny]) continue;
        ret = max(ret, dfs(nx, ny) + 1);
    }
    return ret;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    memset(memo, -1, sizeof(memo));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans = max(ans, dfs(i, j));
    cout << ans;
}