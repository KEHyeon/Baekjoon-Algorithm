#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans;
int parent[10001];
int find(int x) {
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}
void Union(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    if(pa != pb) {
        if (parent[pa] > parent[pb]) parent[pb] = pa;
        else parent[pa] = pb;
    }
}
int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        int pay; cin >> pay;
        parent[i] -= pay;
    }
    while(m--) {
        int a, b; cin >> a >> b;
        Union(a, b);
    }
    for(int i = 1; i <= n; i++) {
        if(parent[i] < 0) ans -= parent[i];
    }
    if(ans > k) cout << "Oh no";
    else cout << ans;
}