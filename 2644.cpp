#include <bits/stdc++.h>
using namespace std;
int n, s, e, m;
vector<int> graph[101];
int dist[101];
int main() {
    cin >> n >> s >> e >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dist[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int nxt : graph[cur]) {
            if(dist[nxt]) continue;
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }
    cout << dist[e] - 1;
}