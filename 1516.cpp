#include <bits/stdc++.h>
using namespace std;
int n;
int t[501], deg[501], memo[501];
vector<int> graph[501];
int main() {
    for(int i = 0; i <= 501; i++) memo[i] = -123456789;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
        int x; cin >> x;
        while(x != -1) {
            graph[x].push_back(i);
            deg[i]++;
            cin >> x;
        }
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) {
            q.push(i);
            memo[i] = t[i];
        }
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int nxt : graph[cur]) {
            deg[nxt]--;
            if(memo[nxt] < memo[cur] + t[nxt]) {
                memo[nxt] = memo[cur] + t[nxt];
            }
            if(deg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    for(int i = 1; i <= n ; i++) {
        cout << memo[i] << "\n";
    }
}