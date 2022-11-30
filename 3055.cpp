#include <bits/stdc++.h>

using namespace std;

int r, c;
char arr[50][50];
int waterDist[50][50];
int goDist[50][50];
pair<int,int> goal;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int main() {
    cin >> r >> c;
    queue<pair<int,int>> wQ;
    queue<pair<int,int>> dQ;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == '*') {
                wQ.push({i,j});
                waterDist[i][j] = 1;
            }
            if(arr[i][j] == 'S') {
                dQ.push({i,j});
                goDist[i][j] = 1;
            }
        }
    }
    while(!wQ.empty()) {
        auto cur = wQ.front(); wQ.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(waterDist[nx][ny] || arr[nx][ny] == 'X' || arr[nx][ny] == 'D') continue;
            waterDist[nx][ny]  = waterDist[cur.first][cur.second] + 1;
            wQ.push({nx, ny});
        }
    }

    while(!dQ.empty()) {
        auto cur = dQ.front(); dQ.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(goDist[nx][ny] || arr[nx][ny] == 'X') continue;
            if(arr[nx][ny] == 'D') {
                cout << goDist[cur.first][cur.second];
                return 0;
            }
            if(goDist[cur.first][cur.second] + 1 >= waterDist[nx][ny] && waterDist[nx][ny] != 0) continue;
            goDist[nx][ny] = goDist[cur.first][cur.second] + 1;
            dQ.push({nx, ny});
        }
    }
    cout << "KAKTUS";
}