#include <bits/stdc++.h>
using namespace std;
bool sleep[6000];
int ans[6000];
int n, k, q, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> q >> m;
    for(int i = 0; i < k; i++) {
        int x; cin >> x;
        sleep[x] = 1;
    }
    for(int i = 0; i < q; i++) {
        int x; cin >> x;
        if(sleep[x]) continue;
        for(int j = 1; j * x <= n + 2; j++) {
            if(sleep[j * x]) continue;
            ans[j * x] = 1;
        }
    }
    for(int i = 3; i <= n + 2; i++) {
        ans[i] = ans[i - 1] + ans[i];
    }
    while(m--) {
        int a, b; cin >> a >> b;
        cout << (b - a + 1) - (ans[b] - ans[a - 1]) << '\n';
    }
}