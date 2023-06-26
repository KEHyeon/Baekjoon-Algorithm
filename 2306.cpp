#include <bits/stdc++.h>

using namespace std;
string str;
int n, memo[500][500], ans;
int dp(int l, int r) {
    if(l + 1 == r) {
        if(str[l] == 'a' && str[r] == 't') return 1;
        if(str[l] == 'g' && str[r] == 'c') return 1;
        return 0;
    }
    int &ret = memo[l][r]; ret = 0;
    if(str[l] == 'a' && str[r] == 't') ret |= dp(l + 1, r - 1);
    if(str[l] == 'g' && str[r] == 'c') ret |= dp(l + 1, r - 1);
    for(int i = l + 1; i < r - 1; i++) {
        ret |= (dp(l, i) && dp(i + 1, r));
    }
    return ret;
}
int main() {
    cin >> str; n = str.size();
    memset(memo, -1, sizeof(memo));
    cout << dp(0, n - 1);
}