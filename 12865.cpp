#include <bits/stdc++.h>
int weight[101];
int value[101];
int n, k;
int memo[101][100001];
using namespace std;
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - value[i] < 0) continue;
            memo[i][j] = max(memo[i - 1][j - value[i]] + value[i], memo[i][j - value[i]] + value[i]);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            cout << memo[i][j] << " ";
        }
        cout << "\n";
    }
}