#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, k;
map<pair<string,int>, bool> vis;
int main() {
    cin >> n >> k;
    string strN = to_string(n);
    queue<pair<string, int>> q;
    q.push({strN, 0});
    vis[{strN, 0}] = 1;
    string ans = "0000000";
    while(!q.empty()) {
        string cur = q.front().X;
        int curDist = q.front().Y; q.pop();
        int len = cur.size();
        if(curDist == k) {
            ans = max(cur, ans);
            continue;
        }
        for(int i = 0; i < len; i++) {
            for(int j = i + 1; j < len; j++) {
                string nxt = cur;
                swap(nxt[i], nxt[j]);
                if(nxt[0] == '0') continue;
                if(vis[{nxt, curDist + 1}]) continue;
                vis[{nxt, curDist + 1}] = 1;
                q.push({nxt, curDist + 1});
            }
        }
    }
    if(ans == "0000000") cout << -1;
    else cout << ans;
}