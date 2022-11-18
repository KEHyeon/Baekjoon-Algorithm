#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1000][1000], ans;
int memo[1000][1000];
const int big = 1000000000;
int dx[3] = {-1, -1, 0};
int dy[3] = {0, -1, -1};
int solve(int x, int y) {
    if(arr[x][y] != 0) return 0;
    if(x == 0 || y == 0) return 1;
    int &ret = memo[x][y];
    if(ret != 0) return ret;
    ret = big;
    for(int i = 0; i < 3; i++) {
        ret = min(ret, solve(x + dx[i], y + dy[i]) + 1);
    }
    return ret == big ? 1 : ret;
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char x; cin >> x;
            if(x == '1') arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] != 0) continue;
            ans = max(ans, solve(i, j));
        }
    }
    cout << ans * ans;
}