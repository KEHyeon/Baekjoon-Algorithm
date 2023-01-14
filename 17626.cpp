#include <bits/stdc++.h>
using namespace std;
int n, memo[50001];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int &ret = memo[i];
        ret = 1234567;
        for(int j = 1; j * j <= i; j++) {
            ret = min(memo[i - j * j] + 1, ret);
        }
    }
    cout << memo[n];
}