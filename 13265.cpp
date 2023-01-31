#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1001];
int color[1001];
int main() {
    int tc; cin >> tc;
    while(tc--) {
        for(int i = 0; i < 1001; i++) adj[i].clear();
        memset(color, 0, sizeof(color));
        cin >> n >> m;
        while(m--) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        string ans = "possible";
        for(int i = 1; i <= n; i++) {
            if(color[i] == 0) {
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while(!q.empty()) {
                    int cur = q.front(); q.pop();
                    for(int nxt : adj[cur]) {
                        if(color[nxt]) {
                            if(color[cur] == color[nxt]) {
                                ans = "impossible";
                            }
                            continue;
                        }
                        color[nxt] = 1 + (color[cur] == 1);
                        q.push(nxt);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}