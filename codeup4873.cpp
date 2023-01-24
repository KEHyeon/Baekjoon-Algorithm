#include <bits/stdc++.h>
using namespace std;
int arr[200000];
int main() {
    int tc; cin >> tc;
    while(tc--) {
        int a1, a2, a3, a4; cin >> a1 >> a2 >> a3 >> a4;
        if(a1 == 0) {
            cout << (a2 || a3 || a4);
        }
        else if(a2 == 0 && a3 == 0) {
            cout << a1 + min(a1 + 1, a4);
        }
        else if(a3 == 0 || a2 == 0){
            int aa = min(a3, a2);
            if(a4) {
                if(a1 >= a3) {
                    cout << a1 + a3 + 1;
                }
                else cout << a1 + a1 + 1;
            }
            else {
                if(a1 > a3) {
                    cout << a1 + a3;
                }
                else cout << a1 + a1;
            }
        }
        else {
            int ans = a1 + min(a2, a3) * 2 + min(abs(a2 - a3), a1);
            if(a4) {
                cout << ans + 1;
            }
            else {
                cout << ans;
            }
        }
        cout << '\n';
    }
}