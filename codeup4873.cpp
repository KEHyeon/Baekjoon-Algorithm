#include <bits/stdc++.h>
using namespace std;
int n;
string str[1001];
vector<int> order;
bool adj[26][26];
bool vis[26];
void makeTree() {
    memset(adj, 0, sizeof(adj));
    for(int i = 0; i < n; i++) {
        int nxt = i + 1;
        int len = min(str[i].length(), str[nxt].length());
        for(int j = 0; j < len; j++) {
            if(str[i][j] == str[nxt][j]) continue;
            adj[str[i][j] - 'a'][str[nxt][j] - 'a'] = 1;
            break;
        }
    }
}
void dfs(int here) {
    vis[here] = 1;
    for(int there = 0; there < 26; there++) {
        if(adj[here][there] && !vis[there]) dfs( there);
    }
    order.push_back(here);
}
void topologicalSort() {
    order.clear();
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < 26; i++) if(!vis[i]) dfs(i);
    reverse(order.begin(), order.end());
    for(int i = 0; i < 26; i++) {
        for(int j = i + 1; j < 26; j++) {
            if(adj[order[j]][order[i]]) {
                order.clear();
                return;
            }
        }
    }
}
int main() {
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> str[i];
        }
        makeTree();
        topologicalSort();
        if(order.size() == 0) cout << "INVALID HYPOTHESIS\n";
        else {
            for(int i : order) cout << char(i + 'a');
            cout << '\n';
        }
    }
}