#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, k, s;
vector<pii> l;
vector<pii> r;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if(a < s) l.push_back({-a, b});
        else r.push_back({a, b});
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int b = 0, ans = 0, temp = -1;
    if(l.size()) temp = -l.back().X;
    while(l.size()) {
        if(b + l.back().Y > k) {
            ans += (s - temp) * 2;
            l[l.size() - 1].Y -= k - b;
            temp = -l.back().X;
            b = 0;
        } else {
            b += l.back().Y;
            l.pop_back();
        }
    }
    if(temp != -1) ans += (s - temp) * 2;
    temp = -1, b = 0;
    if(r.size()) temp = r.back().X;
    while(r.size()) {
        if(b + r.back().Y > k) {
            ans += (temp - s) * 2;
            r[r.size() - 1].Y -= k - b;
            temp = r.back().X;
            b = 0;
        } else {
            b += r.back().Y;
            r.pop_back();
        }
    }
    if(temp != -1) ans += (temp - s) * 2;
    cout << ans;
}