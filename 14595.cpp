#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, m, arr[1000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while(m--) {
        int x, y; cin >> x >> y;
        arr[x]--; arr[y]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        arr[i] += arr[i - 1];
        if(arr[i] == 0) ans++;
    }
    cout << ans;
}