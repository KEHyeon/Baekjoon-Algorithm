#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
vector<string> str(50);
bool isUsed[26];
void bt(int s, int depth) {
    cout << depth << "\n";
    if(depth == k) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int flag = 1;
            for(int j = 0; j < str[i].size(); j++) {
                if(!isUsed[str[i][j] - 'a']) {
                    flag = 0;
                    break;
                }
            }
            if(flag) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }
    for(int i = s; i < 26; i++) {
        if(isUsed[i]) continue;
        isUsed[i] = 1;
        bt(i + 1, depth + 1);
        isUsed[i] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    isUsed['a'-'a'] = isUsed['c'-'a'] = isUsed['i'-'a'] = isUsed['n'-'a'] = isUsed['t'-'a'] = 1;
    k -= 5;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
    }
    bt(0, 0);
    cout << ans;
}