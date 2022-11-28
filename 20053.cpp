#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int MIN = 1000000000;
        int MAX = -100000000;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x > MAX) MAX = x;
            if(x < MIN) MIN = x;
        }
        cout << MIN << " " << MAX << "\n";
    }
}