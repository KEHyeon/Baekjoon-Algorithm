#include <bits/stdc++.h>
using namespace std;
string ans;
void f(int x) {
    if(x == 0 || x == 1) {
        ans += x % 2 ? '7' : '4';
        return;
    }
    f(x / 2);
    ans += x % 2 ? '7' : '4';
}
int main() {
    int k; cin >> k;
    int n = 1, sum = 0;
    while(sum + (1 << n) < k) sum += (1 << n++);
    int num = k - sum;
    f(num - 1);
    for(int i = 0; i < n - ans.size(); i++) {
        cout << '4';
    }
    cout << ans;
}