#include <bits/stdc++.h>
using namespace std;
string board;
int main() {
    cin >> board;
    board += '.';
    int cnt = 0;
    string ans;
    for(int i = 0; i < board.size(); i++) {
        if(board[i] == 'X') cnt++;
        else {
            if(cnt % 2) {
                cout << -1;
                return 0;
            }
            for(int j = 0; j < cnt / 4; j++) ans += "AAAA";
            if(cnt % 4) ans += "BB";
            cnt = 0;
            if(i != board.size() - 1) ans += '.';
        }
    }
    cout << ans;
}