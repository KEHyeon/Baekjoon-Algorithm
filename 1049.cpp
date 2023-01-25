#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    int min6 = 123456, min1 = 123456;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        min6 = min(a, min6);
        min1 = min(b, min1);
    }
    int ans = 123456789;
    ans = min((n % 6 == 0 ? n / 6 : (n / 6 + 1)) * min6, min1 * n);
    ans = min(ans, min1 * (n % 6) + min6 * (n / 6));
    cout << ans;
}