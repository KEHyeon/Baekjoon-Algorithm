#include <bits/stdc++.h>
using namespace std;
int tc, n, arr[500], memo[500][500];

int main() {
    cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];
        memset(memo, 0, sizeof(memo));
        memo[0] = arr[0];
        memo[1] = arr[0] + arr[1];
        for(int i = 2; i < n; i++) {
            memo[i] = min(( arr[i] + arr[i - 1]) * 2 + memo[i - 2], arr[i] + memo[i - 1]);
        }
        cout << memo[n - 1] << "\n";
    }
}