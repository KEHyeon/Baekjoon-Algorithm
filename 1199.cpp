#include <bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
using namespace std;
int n;
vector<int> adj[1000];
int graph[1000][1000];
int de[1000];
vector<int> circuit;
void dfs(int cur) {
    while(adj[cur].size()) {
        int nxt = adj[cur][adj[cur].size() - 1];
        if(graph[cur][nxt] == 0) {
            adj[cur].pop_back();
            continue;
        }
        while(graph[cur][nxt]) {
            graph[cur][nxt]--;
            graph[nxt][cur]--;
            dfs(nxt);
        }
    }
    circuit.push_back(cur);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x; cin >> x;
            graph[i][j] = x;
            de[i] += x;
            if(x) {
                adj[i].push_back(j);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if((de[i]) % 2) {
            cout << -1;
            return 0;
        }
    }
    dfs(0);
    for(int i : circuit) cout << i + 1 << " ";
}