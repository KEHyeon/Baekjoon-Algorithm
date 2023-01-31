#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, m, t;
int s, g, h;
bool goal[2001];
vector<pii> adj[2001];
int dist[2001][2];
int main() {
    int tc; cin >> tc;
    while(tc--) {
        memset(goal, 0, sizeof(goal));
        for(int i = 0; i < 2001; i++) adj[i].clear();
        for(int i = 0; i < 2001; i++) {
            for(int j = 0; j < 2; j++) {
                dist[i][j] = 12345678;
            }
        }
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        while(m--) {
            int a, b, c; cin >> a >> b >> c;
            adj[a].push_back({c, b});
            adj[b].push_back({c, a});
        }
        while(t--) {
            int x;
            cin >> x;
            goal[x] = 1;
        }
        priority_queue<pair<pii, bool>, vector<pair<pii, bool>>, greater<pair<pii, bool>>> pq;
        dist[s][0] = 0;
        pq.push({{0, s}, 0});
        vector<int> ans;
        while(!pq.empty()) {
            auto[cost, cur] = pq.top().X;
            bool can = pq.top().Y; pq.pop();
            if(dist[cur][can] < cost) continue;
            if(can && goal[cur]) {
                cout << cost << " ";
                ans.push_back(cur);
            }
            for(auto [c, nxt] : adj[cur]) {
                c = cost + c;
                if((nxt == g && cur == h) || (cur == g && nxt == h)) {
                    if (dist[nxt][1] > c) {
                        dist[nxt][1] = c;
                        pq.push({{c, nxt}, 1});
                    }
                } else {
                    if (dist[nxt][can] > c) {
                        dist[nxt][can] = c;
                        pq.push({{c, nxt}, can});
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        for(int i : ans) {
            cout << i << " ";
        }
        cout << '\n';
    }
}