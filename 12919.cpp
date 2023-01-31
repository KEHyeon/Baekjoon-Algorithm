#include <bits/stdc++.h>

using namespace std;
string a, b;
bool bt(string x) {
    if(x.size() == a.size()) {
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != x[i]) return 0;
        }
        return 1;
    }
    if(x[0] == 'A' && x[x.size() - 1] == 'B') return 0;
    bool ret = 0;
    if(x[0] == 'B') {
        string temp = x;
        reverse(temp.begin(), temp.end()) ;
        temp.pop_back();
        ret |= bt(temp);
    }
    if(x[x.size() - 1] == 'A') {
        string temp = x;
        temp.pop_back();
        ret |= bt(temp);
    }
    return ret;
}
int main() {
    cin >> a >> b;
    cout << bt(b);
}