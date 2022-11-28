#include <bits/stdc++.h>
using namespace std;
string ans;
void solve(int num) {
    string cur = "";
    while(num > 0) {
        cur = char(num % 2 + '0') + cur;
        num /= 2;
    }
    if(ans.size() == 0) {
        ans = cur;
    }
    else {
        while(cur.size() != 3) {
            cur = '0' + cur;
        }
        ans += cur;
    }
}
int main() {
    string number; cin >> number;
    if(number == "0") {
        cout << 0;
        return 0;
    }
    int len = number.length();
    for(int i = 0; i < len; i++) {
        solve(number[i] - '0');
    }
    cout << ans;
}