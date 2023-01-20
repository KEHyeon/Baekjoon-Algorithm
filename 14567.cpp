#include <bits/stdc++.h>
using namespace std;

int ind[1001];
int n, m;
vector<int> graph[1001];
int dist[1001];
int main() {
    cin >> n >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        ind[b]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(ind[i] == 0) {
            dist[i] = 1;
            q.push(i);
        }
    }

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int nxt : graph[cur]) {
            ind[nxt]--;
            if(ind[nxt] == 0) {
                q.push(nxt);
                dist[nxt] = dist[cur] + 1;
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << dist[i] << " ";
}