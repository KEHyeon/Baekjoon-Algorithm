#include <bits/stdc++.h>
using namespace std;
int main() {
    int tc; cin >> tc;
    while(tc--) {
        int n, m; cin >> n >> m;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x > m) cnt++;
        }
        cout << cnt + 1 << '\n';
    }
}