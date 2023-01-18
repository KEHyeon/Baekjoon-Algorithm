#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[2000][2000];
int arr[2000];
int n;

ll joi(int l, int r);
ll ioi(int l, int r);

inline int Plus(int x){return (x + 1) % n;}
inline int Minus(int x){return (x + n - 1) % n;}
ll joi(int l, int r) {
    if(l == Plus(r)) return 0;
    ll &ret = dp[l][r];
    if(ret != 0) return ret;
    ll a = arr[Minus(l)] + ioi(Minus(l), r);
    ll b = arr[Plus(r)] + ioi(l, Plus(r));
    return ret = max(a, b);
}

ll ioi(int l, int r) {
    if(Minus(l) == r) return 0;
    if(arr[Minus(l)] > arr[(Plus(r))]) return joi(Minus(l), r);
    else return joi(l, Plus(r));
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, arr[i] + ioi(i, i));
    }
    cout << ans;
}