#include <bits/stdc++.h>
using namespace std;
string ducks;
int cnt, len, total;
bool flag;
bool RemoveDuck() {
    string com = "kcauq";
    bool a = 1;
    for(int i = 0; i < len; i++) {
        if(ducks[i] == com[com.size() - 1]) {
            a = 0;
            com.pop_back();
            ducks[i] = '0';
            total++;
            if(com.size() == 0) com = "kcauq";
        }
    }
    cnt++;
    if(com.size() != 5 || a) {
        flag = 1;
        return 0;
    }
    if(len == total) return 0;
    if(len - total < 5) {
        flag = 1;
        return 0;
    }
    return 1;
}
int main() {
    cin >> ducks;
    len = ducks.size();
    while(RemoveDuck()) {
    }
    if(!flag) cout << cnt;
    else cout << -1;
}