#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n;
vector<int> arr;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n; arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            ans += upper_bound(arr.begin() + j + 1, arr.end(), -sum) - lower_bound(arr.begin() + j + 1, arr.end(), -sum);
        }
    }
    cout << ans;
}