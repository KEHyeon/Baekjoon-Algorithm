#include <bits/stdc++.h>

using namespace std;
int n;
int arr[100][100];
long long int cnt[100][100];
long long int dp(int x, int y) {
    if(x >= n || y >= n) return 0;
    if(x == n - 1 && y == n - 1) return 1;
    long long int &ret = cnt[x][y];
    if(ret != -1) return ret;
    ret = 0;
    ret += dp(x + arr[x][y], y);
    ret += dp(x, y + arr[x][y]);
    return ret;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            cnt[i][j] = -1;
        }
    }
    cout << dp(0, 0);
}