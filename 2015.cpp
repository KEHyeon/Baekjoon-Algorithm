#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
ll n, k, arr[200001];
map<ll,int> ck;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    ll ans = 0;
    ck[0]++;
    for(int i = 1; i <= n; i++) {
        ans += ck[arr[i] - k];
        ck[arr[i]]++;
    }
    cout << ans;
}