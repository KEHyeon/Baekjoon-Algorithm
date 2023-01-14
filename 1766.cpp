#include <bits/stdc++.h>
using namespace std;
int n, m;
int deg[32001];
vector<int> graph[32001];
int main() {
    cin >> n >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        deg[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) pq.push(i);
    }
    while(!pq.empty()) {
        int cur = pq.top(); pq.pop();
        cout << cur << " ";
        for(int nxt : graph[cur]) {
            deg[nxt]--;
            if(deg[nxt] == 0) {
                pq.push(nxt);
            }
        }
    }
}