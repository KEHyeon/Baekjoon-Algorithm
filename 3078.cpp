#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    queue<int> q[21];
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        int len = s.size();
        while(!q[len].empty() && i - q[len].front() > k) q[len].pop();
        ans += q[len].size();
        q[len].push(i);
    }
    cout << ans;
}