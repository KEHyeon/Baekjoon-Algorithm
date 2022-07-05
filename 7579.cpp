#include <bits/stdc++.h>
using namespace std;
int n, m, sum;
int b[100];
int c[100];
int dp[100][10001];
int min(int a, int b) {
    return a > b ? b : a;
}
int f(int num, int now,int s) {
    if(s >= m) return now;
    if(num < 0) return -123456789;
    if(dp[num][now]) return dp[num][now];
    return dp[num][now] = max(f(num-1,now-c[num], s + b[num]), f(num - 1, now, s));
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        sum += c[i];
    }
    cout << sum - f(n - 1, sum, 0);
}