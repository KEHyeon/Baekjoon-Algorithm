#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, m, cnt = 1, vis[50][50];;
string arr[50];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool dfs(pii cur, pii pre) {
    vis[cur.X][cur.Y] = cnt;
    bool ret = 0;
    for(int i = 0; i < 4; i++) {
        int nx = cur.X + dx[i];
        int ny = cur.Y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(arr[cur.X][cur.Y] != arr[nx][ny]) continue;
        if(make_pair(nx, ny) == pre) continue;
        if(vis[nx][ny]) {
            if(vis[nx][ny] == cnt) return 1;
            continue;
        }
        ret |= dfs({nx, ny}, cur);
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] == 0) {
                if(dfs({i, j}, {-1, -1})) {
                    cout << "Yes";
                    return 0;
                }
                cnt++;
            }
        }
    }
    cout << "No";
}