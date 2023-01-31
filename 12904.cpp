#include <bits/stdc++.h>
using namespace std;
string a, b;
int main() {
    cin >> a >> b;
    while(b.size() > a.size()) {
        if(b[b.size() - 1] == 'A') b.pop_back();
        else {
            b.pop_back();
            reverse(b.begin(), b.end());
        }
    }
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != b[i]) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
}