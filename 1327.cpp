#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, k, ans = 0;
string str;
map<string, int> vis;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        char x; cin >> x; str += x;
    }
    queue<string> q;
    q.push(str);
    vis[str] = 1;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int s = vis[cur];
        bool flag = 1;
        for(int i = 0; i < cur.size() - 1; i++) {
            if(cur[i] > cur[i + 1]) {
                flag = 0; break;
            }
        }
        if(flag) {
            ans = s;
            break;
        }
        for(int i = 0; i < n - k + 1; i++) {
            string nxt = cur;
            reverse(nxt.begin() + i, nxt.begin() + i + k);
            if(vis[nxt]) continue;
            vis[nxt] = s + 1;
            q.push(nxt);
        }
    }
    cout << ans - 1;
}