#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;
int n, m;
vector<tuple<ll,ll,ll>> arr;
bool check(int x) {
    ll sum = 0;
    for(auto i : arr) {
        auto [a, b, c] = i;
        if(a <= x) {
            sum += (b + (x - a) * c);
            if(sum >= m) return true;
        }
    }
    return false;
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        arr.push_back({b / a + 1, a - b % a, a});
    }
    ll s = 0;
    ll e = 2000000000;
    while(s + 1 < e) {
        ll mid = (s + e) / 2;
        if(check(mid)) {
            e = mid;
        }
        else s = mid;
    }
    cout << e;
}