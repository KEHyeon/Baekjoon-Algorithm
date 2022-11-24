#include <bits/stdc++.h>
using namespace std;
int n, m, board[50][50], memo[50][50], flag, ans;
bool vis[50][50];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int solve(int x, int y) {
    if(board[x][y] == 0) return 0;
    int &ret = memo[x][y];
    if(ret != 0) return ret;
    int power = board[x][y];
    for(int i = 0; i < 4; i++) {
        int nx = x + power * dx[i];
        int ny = y + power * dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
            ret = max(ret, 1);
            continue;
        }
        if(vis[nx][ny]) {
            flag = 1; return 0;
        }
        vis[nx][ny] = 1;
        ret = max(ret, 1 + solve(nx, ny));
        vis[nx][ny] = 0;
    }
    return flag ? -1 : ret;
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x; cin >> x;
            if(x == 'H') continue;
            else board[i][j] = x - '0';
        }
    }
    vis[0][0] = 1;
    cout << solve(0, 0);
}