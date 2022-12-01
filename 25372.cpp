#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;cin >> tc;
    while(tc--) {

        string a; cin >> a;
        if(a.size() >= 6 && a.size() <= 9) cout << "yes\n";
        else cout << "no\n";
    }
}