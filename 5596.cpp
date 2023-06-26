#include <bits/stdc++.h>
using namespace std;
int a, b;
int main() {
    for(int i = 0; i < 4; i++) {
        int x; cin >> x; a += x;
    }
    for(int i = 0; i < 4; i++) {
        int x; cin >> x; b += x;
    }
    cout << max(a, b);
}