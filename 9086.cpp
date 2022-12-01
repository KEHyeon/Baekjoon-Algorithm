#include <bits/stdc++.h>

using namespace std;
int main() {
    int tc; cin >> tc;
    while(tc--) {
        string a; cin >> a;
        cout << a[0] << a[a.size() - 1];
        cout << '\n';
    }
}