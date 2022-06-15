#include <bits/stdc++.h>

using namespace std;
int tc, a, b;
int main() {
    cin >> tc;
    while(tc--){
        cin >> a >> b;
        int ans = 1;
        for(int i = 0; i < b; i++) {
            ans = ans * a % 10;
        }
        if(ans == 0) ans = 10;
        cout << ans << "\n";
    }
}