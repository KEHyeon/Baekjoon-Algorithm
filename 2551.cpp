#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll cnt[10001], n;
vector<ll> num;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    for(int i = 1; i < 10001; i++) {
        if(cnt[i]) num.push_back(i);
    }
    ll len = num.size();
    ll ans1, ans2;
    ll ansSum1 = LONG_LONG_MAX, ansSum2 = LONG_LONG_MAX;
    for(ll i = 1; i < 20001; i++) {
        ll sum1 = 0, sum2 = 0;
        for(ll j = 0; j < len; j++) {
            sum1 += abs(i - num[j]) * cnt[num[j]];
            sum2 += (i - num[j]) * (i - num[j]) * cnt[num[j]];
        }
        if(ansSum1 > sum1) {
            ansSum1 = sum1;
            ans1 = i;
        }
        if(ansSum2 > sum2) {
            ansSum2 = sum2;
            ans2 = i;
        }
    }
    cout << ans1 << " " << ans2;
}