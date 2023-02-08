#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, l, r, ans;
int arr[50][50];
bool vis[50][50];
int dx[4] = {0, -1, 1, 0};
int dy[4] = {1, 0, 0, -1};
int main() {
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    bool flag = 1;
    while(flag) {
        flag = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j]) {
                    vis[i][j] = 1;
                    queue<pii> q;
                    vector<pii> change;
                    q.push({i, j});
                    change.push_back({i, j});
                    int sum = arr[i][j];
                    while(!q.empty()) {
                        auto cur = q.front(); q.pop();
                        for(int k = 0; k < 4; k++) {
                            int nx = cur.X + dx[k];
                            int ny = cur.Y + dy[k];
                            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                            if(vis[nx][ny]) continue;
                            int diff = abs(arr[cur.X][cur.Y] - arr[nx][ny]);
                            if(diff < l || diff > r) continue;
                            flag = 1;
                            vis[nx][ny] = 1;
                            q.push({nx, ny});
                            sum += arr[nx][ny];
                            change.push_back({nx, ny});
                        }
                    }
                    int cnt = change.size();
                    while(!change.empty()) {
                        auto c = change.back();
                        change.pop_back();
                        arr[c.X][c.Y] = sum / cnt;
                    }
                }
            }
        }
        if(flag == 1) ans++;
    }
    cout << ans;
}