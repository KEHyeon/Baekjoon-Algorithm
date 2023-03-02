#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, k;
vector<int> arr, d;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    ll ans = 0;
    for(int i = 0; i < n - 1; i++) {
        ans += arr[i + 1] - arr[i];
        d.push_back(arr[i + 1] - arr[i]);
    }
    sort(d.begin(), d.end());
    for(int i = d.size() - 1; i >= int(d.size()) - (k - 1) && i >= 0; i--) ans -= d[i];
    cout << ans;
}