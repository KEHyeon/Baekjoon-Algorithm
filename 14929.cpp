#include <bits/stdc++.h>
using namespace std;

int n, arr[100001], sum[1000001];
long long int ans;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    for(int i = 1; i <= n; i++) {
        ans += arr[i] * (sum[n] - sum[i]);
    }
    cout << ans;
}
