#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,pair<int,int>>
using namespace std;
int n;
string room[50];
int dist[50][50];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dist[i][j] = 123456;
        }
    }
    for(int i = 0; i < n; i++) {
        cin >> room[i];
    }
    dist[0][0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, {0, 0}});
    while(!pq.empty()) {
        auto[cost, cur] = pq.top(); pq.pop();
        if(cur == make_pair(n - 1, n - 1)) {
            cout << cost;
            return 0;
        }
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            int c = dist[cur.X][cur.Y] + (room[nx][ny] == '0');
            if(dist[nx][ny] > c) {
                dist[nx][ny] = c;
                pq.push({c, {nx, ny}});
            }
        }
    }
}