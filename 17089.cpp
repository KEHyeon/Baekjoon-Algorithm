#include <bits/stdc++.h>
using namespace std;
int frd[4001];
bool isFriend[4001][4001];
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        frd[a]++;
        frd[b]++;
        isFriend[a][b] = 1;
        isFriend[b][a] = 1;
    }
    bool flag = 1;
    int ans = 123456789;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(!isFriend[i][j]) continue;
            for(int k = j + 1; k <= n; k++) {
                if(isFriend[k][j] && isFriend[k][i]) {
                    flag = 0;
                    ans = min(ans, frd[i] + frd[j] + frd[k] - 6);
                }
            }
        }
    }
    if(flag) cout << -1;
    else cout << ans;
}