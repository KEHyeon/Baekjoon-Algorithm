#include <bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
#define ll long long
using namespace std;
int n, m;
vector<pii> arr;
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end());
    ll ans = m;
    int e = arr[0].Y;
    for(int i = 1; i < n; i++) {
        if(arr[i].Y < e) {
            ans += (e - arr[i].Y) * 2;
        }
    }
    cout << ans;
}