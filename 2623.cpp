#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1001];
bool check[1001][1001];
int indegree[1001];
int main() {
    cin >> n >> m;
    while(m--) {
        int nn; cin >> nn;
        int before; cin >> before;
        nn--;
        while(nn--) {
            int x; cin >> x;
            adj[before].push_back(x);
            check[before][x] = 1;
            indegree[x]++;
            before = x;
        }
    }
    queue<int> q;
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            ans.push_back(i);
        }
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int nxt : adj[cur]) {
            indegree[nxt]--;
            if(indegree[nxt] == 0) {
                q.push(nxt);
                ans.push_back(nxt);
            }
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        for(int j = i + 1; j < ans.size(); j++) {
            if(check[ans[j]][ans[i]]) {
                cout << 0;
                return 0;
            }
        }
    }
    if(ans.size() !=    n) {
        cout << 0;
        return 0;
    }
    for(int i : ans) cout << i << "\n";
}