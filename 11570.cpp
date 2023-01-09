#include <bits/stdc++.h>
using namespace std;
int n;
int arr[2001];
int memo[2001][2001]; // memo[x][y]는 마지막 음이 각각x,y일때 최솟값
int f(int x, int y) {
    int now = max(x, y) + 1;
    if(now == n + 1) return 0;
    int &ret = memo[x][y];
    if(ret != -1) return ret;
    if(x == 0) ret = f(now, y);
    else {
        ret = abs(arr[x] - arr[now]) + f(now, y);
    }
    if(y == 0) ret = min(ret, f(x, now));
    else ret = min(ret, abs(arr[y] - arr[now]) + f(x, now));
    return ret;
}
int main() {
    cin >> n;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            memo[i][j] = -1;
        }
    }
    for(int i = 1; i <= n; i++) cin >> arr[i];
    cout << f(0, 0);
}
