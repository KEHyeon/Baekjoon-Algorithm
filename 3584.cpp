#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n;
vector<int> c[10000];
int p[10000];
int r[10000];
void dfs(int cur) {
    for(int nxt : c[cur]) {
        r[nxt] = r[cur] + 1;
        dfs(nxt);
    }
}
int lca(int a, int b) {
    if(r[a] < r[b]) swap(a, b);
    for(; r[a] != r[b]; a = p[a]) ;
    if(a == b) return a + 1;
    while(a != b) {
        a = p[a];
        b = p[b];
    }
    return a + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        memset(r, -1, sizeof(r));
        memset(p, -1, sizeof(p));
        for(int i = 0; i < 10000; i++) c[i].clear();
        cin >> n;
        for(int i = 0; i < n - 1; i++) {
            int a, b; cin >> a >> b;;
            c[a - 1].push_back(b - 1);
            p[b - 1] = a - 1;
        }
        int root;
        for(int i = 0; i < n; i++) {
            if(p[i] == -1) {
                root = i;
                break;
            }
        }
        r[root] = 0;
        dfs(root);
        int a, b; cin >> a >> b;
        cout << lca(a - 1, b - 1) << '\n';
    }
}