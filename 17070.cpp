#include <bits/stdc++.h>
using namespace std;
int n;
bool arr[16][16];
int memo[16][16][3];
int tif(int x, int  y, int dir) {
    if(dir == 2 && (arr[x][y - 1] || arr[x - 1][y])) return 0;
    if(x < 0 || y < 0 || x >= n || y >= n || arr[x][y]) return 0;
    if(x == n - 1 && y == n - 1) return 1;
    int &ret = memo[x][y][dir];
    if(ret != 0) return ret;
    if(dir == 0) {
        ret += tif(x, y + 1, 0);
        ret += tif(x + 1, y + 1, 2);
    }
    if(dir == 1) {
        ret += tif(x + 1, y, 1);
        ret += tif(x + 1, y + 1, 2);
    }
    if(dir == 2) {
        ret += tif(x, y + 1, 0);
        ret += tif(x + 1, y, 1);
        ret += tif(x + 1, y + 1, 2);
    }
    return ret;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cout << tif(0, 1, 0);
}