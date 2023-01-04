#include <bits/stdc++.h>
using namespace std;
int memo[1000][1000][4];
int arr[1000][1000];
const int dx[3] = {0, 1, 0};
const int dy[3] = {-1, 0, 1};
const int MIN = -123456789;
int n, m;
int maxValue(int x, int y, int dir) {
    if(x == n - 1 && y == m - 1)  return arr[x][y];
    if(x < 0 || y < 0 || x >= n || y >= m) return MIN;
    int &ret = memo[x][y][dir];
    if(ret != 0) return ret;
    ret = MIN;
    for(int i = 0; i < 3; i++) {
        if(dir == 0 && i == 2) continue;
        if(dir == 2 && i == 0) continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        ret = max(ret, arr[x][y] + maxValue(nx, ny, i));
    }
    return ret;
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << maxValue(0, 0, 1);
}