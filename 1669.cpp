#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
ll x, y;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> x >> y;
    y -= x;
    if(y == 0) {
        cout << 0;
        return 0;
    }
    ll cnt = 0, i;
    for(i = 1; i * (i + 1) < y; i++) cnt += 2;
    cnt += 2;
    if(i * (i + 1) - i >= y) cout << cnt - 1;
    else cout << cnt;
}