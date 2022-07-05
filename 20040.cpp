#include <bits/stdc++.h>
using namespace std;
int n, m;
int parent[500000];
int find(int x) {
    if(parent[x] == x) {
        return x;
    }
    else {
        return parent[x] = find(parent[x]);
    }
}
void Union(int x, int y) {
    int px = find(x);
    int py = find(y);
    if(px > py) {
        parent[py] = px;
    }
    else parent[px] = py;
}
int main() {
    cin >> n >> m;
    int ans = 0;
    int flag = 1;
    for(int i = 0; i < n; i++) parent[i] = i;
    while(m--) {
        ans++;
        int a, b; cin >> a >> b;
        if(find(a) == find(b)) {
            flag = 0;
            break;
        }
        Union(a, b);
    }
    if(flag) cout << 0;
    else cout << ans;
}