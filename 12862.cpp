#include <bits/stdc++.h>
using namespace std;
int n, limit;
int weight[100];
int value[100];
int dp[101][100001];
int f(int num, int now) {
    if(now < 0) return -123456789;
    if(num < 0) return 0;
    if(dp[num][now]) return dp[num][now];
    return dp[num][now] = max(f(num - 1, now  - weight[num]) + value[num], f(num - 1, now));
}
int main() {
    cin >> n >> limit;
    for(int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }
    cout << f(n - 1, limit) << endl;
}