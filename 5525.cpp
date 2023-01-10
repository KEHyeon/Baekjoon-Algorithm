#include <bits/stdc++.h>
using namespace std;
int n, len, ans;
string str;

int main() {
    cin >> n >> len >> str;
    int pLen = n + 1;
    for(int i = 0; i < len - 2; i++) {
        if(str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I') {
            i += 3;
            int cnt = 2;
            while(i <= len - 2 && str[i] == 'O' && str[i + 1] == 'I') {
                cnt++;
                i += 2;
            }
            if(i < len - 2) {
                i -= 1;
            }
            if(cnt < pLen) continue;
            ans += cnt - pLen + 1;
        }
    }
    cout << ans;
}