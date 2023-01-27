#include <bits/stdc++.h>
using namespace std;
int h, w;
int dist[500][500];
string arr[500];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int main() {
    cin >> h >> w;
    for(int i = 0; i < h; i++) cin >> arr[i];
    dist[0][0] = 1;
    queue<pair<int,int>> q;
    q.push({0, 0});
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(arr[cur.first][cur.second] == arr[nx][ny]) continue;
            if(dist[nx][ny]) continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }
    if(dist[h - 1][w - 1] == 0) cout << -1;
    else cout << dist[h - 1][w - 1] - 1;
}