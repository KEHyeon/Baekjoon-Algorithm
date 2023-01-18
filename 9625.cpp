#include <bits/stdc++.h>
using namespace std;
int a[46] = {1};
int b[46];

int main() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        a[i] = b[i - 1];
        b[i] = a[i - 1] + b[i - 1];
    }
    cout << a[n] << " " << b[n];
}