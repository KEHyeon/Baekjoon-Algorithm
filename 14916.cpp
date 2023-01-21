#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main() {
    cin >> n;
    if(n == 1 || n == 3) {
        cout << -1;
        return 0;
    }
    ans += n / 5;
    if(n % 5 % 2) ans += (n % 5 + 5) / 2 - 1;
    else ans += n % 5 / 2;
    cout << ans;
}