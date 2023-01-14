#include <bits/stdc++.h>
using namespace std;
int n;
long long int memo[36];
long long int dp(int x) {
    if(x == 0) return 1;
    long long int &ret = memo[x];
    if(ret) return ret;
    for(int i = 0; i < x; i++) {
        ret += dp(i) * dp(x - i - 1);
    }
    return ret;
}
int main() {
    cin >> n;
    cout << dp(n);
}