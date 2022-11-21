#include <bits/stdc++.h>
using namespace std;
int tc, n, arr[500], memo[500][500], sum[501];
int solve(int a, int b) {
    if(a == b) return 0;
    int &ret = memo[a][b];
    if(ret != 0) return ret;
    ret = 123456789;
    for(int i = a; i < b; i++) {
        ret = min(ret, solve(a, i) + solve(i + 1, b));
    }
    return ret += sum[b + 1] - sum[a];
}
int main() {
    cin >> tc;
    while(tc--) {
        memset(memo, 0, sizeof(memo));
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            sum[i + 1] = sum[i] + arr[i];
        }
        cout << solve(0, n - 1) << "\n";
    }
}