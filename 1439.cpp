#include <bits/stdc++.h>
using namespace std;
string str;
int cnt[2];
int main() {
    cin >> str;
    char cur = str[0];
    cnt[str[0] - '0']++;
    for(int i = 1; i < str.size(); i++) {
        if(str[i] != cur) {
            cur = str[i];
            cnt[str[i] - '0']++;
        }
    }
    if(cnt[0] + cnt[1] == 1) cout << 0;
    else cout << min(cnt[0], cnt[1]);
}