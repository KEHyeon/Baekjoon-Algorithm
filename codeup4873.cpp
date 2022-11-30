#include <bits/stdc++.h>
using namespace std;
int n, q;
int parent[200001];
vector<int> tree[200001];

void dfs(int node,int p) {
    parent[node] = p;
    for(auto nxt : tree[node]) {
        if(parent[nxt] == -1) continue;
        dfs(nxt, p);
    }
}

int getParent(int node) {
    if(parent[node] == -1) return node;
    return parent[node] = getParent(parent[node]);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) parent[i] = -1;
    for(int i = 1; i < n; i++) {
        int x; cin >> x;
        tree[x].push_back(i + 1);
        parent[i + 1] = x;
    }
    while(q--) {
        int a, b, c; cin >> a >> b >> c;
        string ans;
        if(getParent(a) == getParent(b)) ans = "YES";
        else ans = "NO";
        if(c) {
            if(ans == "YES" && parent[a] != -1) {
                dfs(a, a);
                parent[a] = -1;
            }
            else if(ans == "NO" && parent[b] != -1){
                dfs(b, b);
                parent[b] = -1;
            }
        }
        cout << ans << "\n";
    }
}

