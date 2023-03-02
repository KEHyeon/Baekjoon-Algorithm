#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, k, arr[10][10];
bool vis[10];
int bt(int d, int now) {
    if(d == n - 1) return 0;
    int ret = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(now == i || vis[i]) continue;
        vis[i] = 1;
        ret = min(arr[now][i] + bt(d + 1, i), ret);
        vis[i] = 0;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin >> arr[i][j];
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                arr[i][j] = min(arr[i][k] + arr[k][j], arr[i][j]);
            }
        }
    }
    vis[k] = 1;
    cout << bt(0, k);
}