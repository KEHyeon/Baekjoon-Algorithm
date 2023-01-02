#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> graph[101];
vector<int> curNode;
vector<int> ansArr;
int vis[101];
int vis2[101];
int main() {
    cin >> n >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        curNode.clear();
        if(!vis[i]) {
            int MIN = -1;
            queue<int> Q;
            Q.push(i);
            vis[i] = 1;
            while(!Q.empty()) {
                int cur = Q.front(); Q.pop();
                MIN = max(MIN, vis[cur]);
                for(int nxt : graph[cur]) {
                    if(vis[nxt]) continue;
                    vis[nxt] = vis[cur] + 1;
                    curNode.push_back(nxt);
                    Q.push(nxt);
                }
            }
            int ans = i;
            for(int j : curNode) {
                int curMax = -1;
                for(int  k = 0; k <= n; k++) vis2[k] = 0;
                Q.push(j);
                vis2[j] = 1;
                while(!Q.empty()) {
                    int cur = Q.front(); Q.pop();
                    curMax = max(curMax, vis2[cur]);
                    for(int nxt : graph[cur]) {
                        if(vis2[nxt]) continue;
                        vis2[nxt] = vis2[cur] + 1;
                        Q.push(nxt);
                    }
                }
                if(MIN > curMax) {
                    MIN = curMax;
                    ans = j;
                }
            }
            ansArr.push_back(ans);
        }
    }
    sort(ansArr.begin(), ansArr.end());
    cout << ansArr.size();
    for(int i : ansArr) {
        cout << "\n" << i;
    }
}