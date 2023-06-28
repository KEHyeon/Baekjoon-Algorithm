#include <bits/stdc++.h>
using namespace std;
string a, b;
int main() {
    cin >> a >> b;
    int i = 0;
    while(i < a.size() && i < b.size() && a[i] == b[i]) {
        i++;
    }
    while(a[a.size() - 1] == b[b.size() - 1]) {
        if(a.size() - 1 == i - 1) break;
        a.pop_back();
        b.pop_back();
        if(a.empty() || b.empty()) break;
    }
    int ans = b.size() - i;
    if(ans <= 0) cout << 0;
    else cout << ans;
}