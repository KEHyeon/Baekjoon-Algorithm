#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MAX =123456789;
int arr[101];
int memo[101][51];
int f(int x, int y) {
    if(y == 0) return 0;
    if(x > n) return -123456789;
    int &ret = memo[x][y];
    if(ret != MAX) return ret;
    ret = -123456789;
    for(int i = x; i <= n; i++) {
        ret = max(ret, arr[i] - arr[x - 1] + f(i + 2, y - 1));
        ret = max(ret, f(i + 1, y));
    }
    return ret;
}
int main() {
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 51; j++) {
            memo[i][j] = MAX;
        }
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] = arr[i - 1] + arr[i];
    }
    cout << f(1, m);
}