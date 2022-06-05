#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int,int> red, blue, goal;
char board[10][10];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int vis[10][10];
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'B') red = {i,j};
            else if(board[i][j] == 'R') blue = {i,j};
            else if(board[i][j] == 'O') goal = {i, j};
        }
    }
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({red, blue});
    while(!q.empty()) {
        auto curR = q.front().first;
        auto curB = q.front().second;
        for(int i = 0; i < 4; i++) {
            auto nxtR = {curR.first + dx[i], curR.second + dy[i]};
            auto nxtB = {curB.first + dx[i], curB.second + dy[i]};
            if()
        }
    }
}
