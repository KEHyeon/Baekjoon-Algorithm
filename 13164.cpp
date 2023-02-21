#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k;
vector<int> arr;
int main() {
    cin >> n >> k;
    int prv; cin >> prv;
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        int x; cin >> x;
        ans += x - prv;
        arr.push_back(x - prv);
        prv = x;
    }
    sort(arr.begin(), arr.end());
    for(int i = arr.size() - 1; i >= int(arr.size()) - k + 1; i--) {
        ans -= arr[i];
    }
    cout << ans;
}