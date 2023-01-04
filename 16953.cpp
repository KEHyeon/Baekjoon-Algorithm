#include <bits/stdc++.h>
using namespace std;
int a, b, cnt;
int main() {
    cin >> a >> b;
    while(b > a) {
        if(b % 10 == 1) b = b / 10;
        else if(b % 2 == 0){
            b /= 2;
        }
        else {
            cout << -1;
            return 0;
        }
        cnt++;
    }
    if(b != a) cout << -1;
    else cout << cnt + 1;
}
