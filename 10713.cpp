#include <bits/stdc++.h>
using namespace std;
int n, m;
long long int ans;
int howUse[100001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int now, nxt;
    cin >> now;
    for(int i = 1; i < m; i++) {
        cin >> nxt;
        int s = min(now, nxt);
        int e = max(now, nxt);
        howUse[s]++;
        howUse[e]--;
        now = nxt;
    }
    for(int i = 1; i <= n; i++) {
        howUse[i] = howUse[i - 1] + howUse[i];ㅋ\
    }
    for(int i = 1; i < n; i++) {
        long long int a, b, c; cin >> a >> b >> c;
        ans += min(a * howUse[i], c + (b * howUse[i]));
    }
    cout << ans;
}