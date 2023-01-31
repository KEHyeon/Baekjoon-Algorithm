#include <bits/stdc++.h>
using namespace std;
int r, c;
string str[1000];
int main() {
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            char x; cin >> x;
            str[j] = x + str[j];
        }
    }
    int cnt = 0;
    while(1) {
        map<string, bool> chk;
        for(int i = 0; i < c; i++) {
            str[i].pop_back();
            if(!chk[str[i]]) {
                chk[str[i]] = 1;
            } else {
                cout << cnt;
                return 0;
            }
        }
        cnt++;
    }
    cout << cnt;
}