#include <bits/stdc++.h>
using namespace std;
int n,c;
pair<int,int> arr[21];
int memo[20][1001];
int dp(int start, int x) {
    if(x <= 0) return 0;
    if(start == n) return 123456789;
    int &ret = memo[start][x];
    if(ret) return ret;
    ret = 123456789;
    for(int i = start; i < n; i++) {
        ret = min(ret, dp(i, x - arr[i].second)+arr[i].first);
    }
    return ret;
}
int main() {
    cin >> c >> n;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr[i] = {a, b};
    }
    cout << dp(0, c);
}