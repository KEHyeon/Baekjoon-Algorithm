#include <bits/stdc++.h>
using namespace std;
int n, m, ans, cycleCnt = 1;
char arr[1001][1001];
int vis[1001][1001];
int dfs(int x, int y) {
    if(vis[x][y]) {
        cycleCnt++;
        if(vis[x][y] == cycleCnt - 1) return 1;
        return 0;
    }
    vis[x][y] = cycleCnt;
    if(arr[x][y] == 'U') return dfs(x - 1, y);
    if(arr[x][y] == 'D') return dfs(x + 1, y);
    if(arr[x][y] == 'L') return dfs(x, y - 1);
    if(arr[x][y] == 'R') return dfs(x, y + 1);
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j]) {
                ans += dfs(i, j);
            }
        }
    }
    cout << ans;
}
