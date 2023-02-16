#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n;
double ans;
double per[4];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool vis[100][100];
void bt(int x, int y, double p, int depth) {
    if(depth == n) {
        ans += p;
        return;
    }
    for(int i = 0; i < 4; i++) {
        if(per[i] == 0) continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        bt(nx, ny, p * per[i] / 100, depth + 1);
        vis[nx][ny] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> per[0] >> per[1] >> per[2] >> per[3];
    vis[50][50] = 1;
    bt(50, 50, 1, 0);
    printf("%.10f", ans);
}