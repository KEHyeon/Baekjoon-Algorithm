#include <bits/stdc++.h>
using namespace std;
int tc;
bool isPal(string str) {
    bool flag = 1;
    int s = 0, e = str.size() - 1;
    while(s <= e) {
        if(str[s] != str[e]) {
            flag = 0;
            break;
        }
        s++, e--;
    }
    return flag;
}
bool isPal2(string str) {
    int flag = 0;
    bool escape = 0;
    int s = 0, e = str.size() - 1;
    while(s <= e) {
        if(str[s] != str[e]) {
            escape = 1;
            if(str[s + 1] == str[e]) {
                int s2 = s + 1;
                int e2 = e;
                int flag2 = 0;
                while(s2 <= e2) {
                    if(str[s2] != str[e2]) {
                        flag2 = 1;
                        break;
                    }
                    s2++;
                    e2--;
                }
                if(flag2 == 0) flag = 1;
            }
            if(str[s] == str[e - 1]) {
                int s2 = s;
                int e2 = e - 1;
                int flag2 = 0;
                while(s2 <= e2) {
                    if(str[s2] != str[e2]) {
                        flag2 = 1;
                        break;
                    }
                    s2++;
                    e2--;
                }
                if(flag2 == 0) flag = 1;
            }
        }
        if(escape) break;
        s++, e--;
    }
    return flag;
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> tc;
    while(tc--) {
        string str; cin >> str;
        if(isPal(str)) cout << 0 << '\n';
        else {
            if(isPal2(str)) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
    }
}