#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int,int>> adj[50001];
int dist[50001];
int n, m;
int main() {
    for(int i = 0; i < 50001; i++) dist[i] = 12345678;
    cin >> n >> m;
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1});
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int curCost = cur.X;
        int curNode = cur.Y;
        if(curCost > dist[curNode]) continue;
        for(auto nxt : adj[curNode]) {
            int nxtCost = curCost + nxt.X;
            int nxtNode = nxt.Y;
            if(dist[nxtNode] > nxtCost) {
                dist[nxtNode] = nxtCost;
                pq.push({nxtCost, nxtNode});
            }
        }
    }
    cout << dist[n];
}