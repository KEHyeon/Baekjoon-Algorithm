#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
ll n, m, ans = LONG_LONG_MAX;
ll arr[100000];
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    ll s = 0, e = 0;
    while(s <= e && e < n) {
        if(abs(arr[s] - arr[e]) < m) e++;
        else {
            ans = min(ans, abs(arr[s] - arr[e]));
            s++;
        }
    }
    cout << ans;
}