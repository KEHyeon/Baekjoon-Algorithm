#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, m;
vector<pii> adj[1001];
int dist[1001];
int info[1001][1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i = 0; i < 1001; i++) {
        for(int j = 0; j < 1001; j++) info[i][j] = 123456789;
    }
    for(int i = 0; i < 1001; i++) dist[i] = 123456789;
    cin >> n >> m;
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        info[a][b] = min(info[a][b], c);
        adj[a].push_back({c, b});
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int a, b; cin >> a >> b;
    dist[a] = 0;
    pq.push({0, a});
    while(!pq.empty()) {
        auto [cost, cur] = pq.top(); pq.pop();
        if(cur == b) {
            break;
        }
        if(dist[cur] < cost) continue;
        for(auto [nxtCost, nxt] : adj[cur]) {
            int c = cost + nxtCost;
            if(dist[nxt] > c) {
                dist[nxt] = c;
                pq.push({c, nxt});
            }
        }
    }
    cout << dist[b] << "\n";
    int cnt = 0;
    int cur = b;
    stack<int> ans;
    ans.push(b);
    while(cur != a) {
        for(int i = 1; i <= n; i++) {
            if(dist[i] + info[i][cur] == dist[cur]) {
                ans.push(i);
                cur = i;
                break;
            }
        }
    }
    cout << ans.size() << "\n";
    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
}