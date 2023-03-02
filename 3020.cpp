#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, h;
int b[500002], t[500002];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> h;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(i % 2) t[h - x + 1]++;
        else b[x]++;
    }
    for(int i = 1; i <= h; i++) {
        t[i] = t[i - 1] + t[i];
        b[h - i] = b[h - i + 1] + b[h - i];
    }
    ll ans = INT_MAX;
    int cnt = 0;
    for(int i = 1; i <= h; i++) {
        if(ans > b[i] + t[i]) {
            ans = b[i] + t[i];
            cnt = 1;
        }
        else if(ans == b[i] + t[i]) cnt++;
    }
    cout << ans << " " << cnt;
}