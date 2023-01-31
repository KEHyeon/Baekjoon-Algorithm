#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
map<int,int> cnt;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    ll ans = 0;
    while(cnt.size() > 0) {
        ll start = cnt.begin()->first;
        cout << start << "\n";
        ll t = 0;
        while(cnt[start]) {
            t++;
            cnt[start]--;
            if(cnt[start] == 0) cnt.erase(start);
            start++;
        }
        ans += (start - 1) * t;
    }
    cout << ans;
}