#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
bool vis[1000][1000];
pair<int,int> parent[1000][1000];
pair<int,int> find(int x, int y) {
    if(parent[x][y].first == x && parent[x][y].second == y) {
        return {x, y};
    }
    return parent[x][y] = find(parent[x][y].first, parent[x][y].second);
}
void Union(pair<int,int> a, pair<int,int> b) {
    pair<int,int> ap = find(a.first, a.second);
    pair<int,int> bp = find(b.first, b.second);
    if(ap != bp) {
        if(a > b) {
            parent[a.first][a.second] = bp;
        }
        else parent[b.first][b.second] = ap;
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            parent[i][j] = {i, j};
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char d; cin >> d;
            if(d == 'U') {
                Union({i,j}, {i - 1, j});
            }
            else if(d == 'D') {
                Union({i,j}, {i + 1, j});
            }
            else if(d == 'L') {
                Union({i,j}, {i, j - 1});
            }
            else {
                Union({i,j}, {i, j +  1});
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j =0 ; j <  m;j++) {
            cout << find(i,j).first << " " << find(i,j).second << "    ";
        }
        cout << "\n";
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x = find(i,j).first;
            int y = find(i,j).second;
            if(vis[x][y] == 0) {
                ans++;
                vis[x][y] = 1;
            }
        }
    }
    cout << ans;
}