#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    a /= 100;
    for(int i = 0; i < 100; i++) {
        if((a * 100 + i) % b == 0) {
            if(i < 10) {
                cout << 0 << i;
            }
            else cout << i;
            return 0;
        }
    }
}