#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector<ll> pos, nag;
bool com(int a, int b) {
    return a > b;
}
int main() {
    cin >> n;
    bool zero = false;
    while(n--) {
        int x; cin >> x;
        if(x > 0) pos.push_back(x);
        else if(x == 0) zero = true;
        else nag.push_back(x);
    }
    sort(pos.begin(), pos.end(), com);
    sort(nag.begin(), nag.end());
    ll ans = 0;
    for(int i = 0; i < pos.size(); i++) {
        if(i == pos.size() - 1) {
            ans += pos[i];
        }
        else if(pos[i + 1] == 1) {
            ans += pos[i] + 1;
        }
        else ans += pos[i] * pos[i + 1];
        i++;
    }
    for(int i = 0; i < nag.size(); i++) {
        if(i == nag.size() - 1) {
            if(zero) continue;
            ans += nag[i];
        }
        ans += nag[i] * nag[i + 1];
        i++;
    }
    cout << ans;
}