#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int r, c, ans;
string arr[1501];
bool vis[1501][1501];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<pii> bird;
queue<pii> q1;
queue<pii> waterQ;
void melt() {
    int len = waterQ.size();
    while(len--) {
        auto cur = waterQ.front(); waterQ.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(arr[nx][ny] == 'X') {
                arr[nx][ny] = '.';
                waterQ.push({nx, ny});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        cin >> arr[i];
        for(int j = 0; j < c; j++) {
            if(arr[i][j] == 'L') {
                bird.push_back({i, j});
                arr[i][j] = '.';
            }
            if(arr[i][j] == '.') {
                waterQ.push({i, j});
            }
        }
    }
    bool flag = 0;
    q1.push({bird[0].X, bird[0].Y});
    vis[bird[0].X][bird[0].Y] = 1;
    while(1) {
        queue<pii> q2;
        while(!q1.empty()) {
            pii cur = q1.front(); q1.pop();
            if(cur == bird[1]) {
                flag = 1;
                break;
            }
            for(int i = 0; i < 4; i++) {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                if(vis[nx][ny]) continue;
                if(arr[nx][ny] == 'X') {
                    q2.push({nx,ny});
                    vis[nx][ny] = 1;
                    continue;
                }
                q1.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
        if(flag == 1) {
            cout << ans;
            return 0;
        }
        q1 = q2;
        melt();
        ans++;
    }
}