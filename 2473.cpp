#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
ll n, arr[5000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    vector<ll> ans(3);
    ll m = LONG_LONG_MAX;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            ll sum = arr[i] + arr[j];
            int idx = lower_bound(arr + j + 1, arr + n, -sum) - arr;
            if(idx != n && std::abs(sum + arr[idx]) < m) {
                m = std::abs(sum + arr[idx]);
                ans = {arr[i], arr[j], arr[idx]};
            }
            if(idx - 1 != j && std::abs(sum + arr[idx - 1]) < m) {
                m = std::abs(sum + arr[idx - 1]);
                ans = {arr[i], arr[j], arr[idx - 1]};
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(int i : ans) cout << i << " ";
}
