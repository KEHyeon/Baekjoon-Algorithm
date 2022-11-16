#include <bits/stdc++.h>
using namespace std;

int memo[10001];
int money[20];
int n;
int dp(int m) {
    if(m == 0) return 1;
    int &ret = memo[m];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < n; i++) {
        if(m - money[i] < 0) continue;
        ret += dp(m - money[i]);
    }
    return ret;
}

int main() {
    int tc; cin >> tc;
    while(tc--) {
        memset(memo, -1, sizeof(memo));
        cin >> n;
        for(int i = 0; i < n; i++) cin >> money[i];
        int goal; cin >> goal;
        dp(goal);
        for(int i = 0; i <= goal; i++) {
            cout << i << " : " << memo[i] << "\n";
        }
    }
}