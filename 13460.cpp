#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, m;
bool flag;
pair<int,int> red, blue, hole;
char board[11][11];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
pair<pair<int,int>,pair<int,int>> go(pair<int,int> r, pair<int,int> b, int dir) {
    while(1) {
        int rnx = r.X + dx[dir];
        int rny = r.Y + dy[dir];
        if(board[rnx][rny] == 'O') {
            flag = 1;
        }
        if(board[rnx][rny] == '#') break;
        if(rnx == b.X && rny == b.Y) {
            while(1) {
                if(board[b.X + dx[dir]][b.Y + dy[dir]] == '#') break;
                if(board[b.X + dx[dir]][b.Y + dy[dir]] == 'O') return {{-1,-1},{-1,-1}};
                b.X += dx[dir];
                b.Y += dy[dir];
            }
            r.X = b.X - dx[dir];
            r.Y = b.Y - dy[dir];
            break;
        }
        r.X = rnx;
        r.Y = rny;
    }
    while(1) {
        int bnx = b.X + dx[dir];
        int bny = b.Y + dy[dir];
        if(board[bnx][bny] == 'O') {
            r = {-1, -1};
            flag = 0;
            return {r, b};
        }
        if(board[bnx][bny] == '#') break;
        if(bnx == r.first && bny == r.second) break;
        b.X = bnx;
        b.Y = bny;
    }
    return {r, b};
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'R') {
                red = {i, j };
                board[i][j] = '.';
            }
            if(board[i][j] == 'B') {
                blue = {i, j };
                board[i][j] = '.';
            }
            if(board[i][j] == 'O') hole = {i, j};
        }
    }
    queue<tuple<pair<int,int>, pair<int,int>, int>> q;
    q.push({red, blue, 0});
    while(!q.empty()) {
        auto [curR, curB, cnt] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            auto nxt = go(curR, curB, i);
            auto rn = nxt.X;
            auto rb = nxt.Y;
            if(rn.X == -1) continue;
            if(flag == 1) {
                cout << cnt + 1;
                return 0;
            }
            if(cnt + 1 == 10) continue;
            q.push({rn, rb, cnt + 1});
        }
    }
    cout << -1;
}