#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int dx[3] = {-1, 0, 1};
int n, m, arr[1001][1001], memo[1001][1001][3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for(int dir = 0; dir < 3; dir++) {
                int &ret = memo[i][j][dir];
                int nx = j + dx[dir];
                if(nx <= 0 || nx > m) continue;
                ret = INT_MAX;
                for(int k = 0; k < 3; k++) {
                    if(dir == k || nx + dx[k] <= 0 || nx + dx[k] > m) continue;
                    ret = min(ret, memo[i - 1][nx][k]);
                }
                ret += arr[i][j];
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < 3; j++) {
            if(i + dx[j] <= 0 || i + dx[j] > m) continue;
            ans = min(ans, memo[n][i][j]);
        }
    }
    cout << ans;
}