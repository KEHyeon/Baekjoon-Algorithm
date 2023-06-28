#include <bits/stdc++.h>
using namespace std;
int n, m, arr[100001], sum[100001];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        sum[a] += c;
        sum[b + 1] -= c;
    }
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + sum[i];
    }
    for(int i = 1; i <= n; i++) cout << arr[i] + sum[i] << " ";
}