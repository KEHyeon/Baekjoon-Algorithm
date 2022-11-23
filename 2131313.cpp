#include <bits/stdc++.h>
using namespace std;
int n, m, c;
int parent[100001];
int country[100001];
int getParent(int node) {
    if(parent[node] == node || parent[node] < 0) return parent[node];
    int p = getParent(parent[node]);
    parent[node] = p;
    return p;
}

void Merge(int a, int b) {
    int ap = getParent(a);
    int bp = getParent(b);
    if(a > b) {
        parent[bp] = ap;
    }
    else parent[ap] = bp;
}
int main() {
    cin >> n;
    cin >> m;
    for(int i = 1; i <= n; i++) parent[i] = i;
    while(m--){
        int a, b; cin >> a >> b;
        Merge(a, b);
    }
    cin >> c;
    while(c--) {
        int a, b; cin >> a >> b;
        int ap = getParent(a);
        country[ap] = b;
    }
    for(int i = 1; i <= n; i++) {
        if(country[getParent(i)] == 0) cout << 0 << " ";
        else cout << country[getParent(i)] << " ";
    }
}
