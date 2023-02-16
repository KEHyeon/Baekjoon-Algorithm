#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<ll,ll>
using namespace std;
int n, m, parent[1000];
pii pla[1000];
int find(int cur) {
    if(parent[cur] < 0) return cur;
    return parent[cur] = find(parent[cur]);
}
int isGroup(int a, int b) {
    a = find(a); b = find(b);
    if(a == b) return 1;
    parent[a] = b;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(parent, -1, sizeof(parent));
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        pla[i] = {a, b};
    }
    while(m--) {
        int a, b; cin >> a >> b;
        isGroup(a - 1, b - 1);
    }
    vector<pair<double, pii>> edge;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            double dist = (pla[i].X - pla[j].X) * (pla[i].X - pla[j].X);
            edge.push_back({sqrt(dist +(pla[i].Y - pla[j].Y) * (pla[i].Y - pla[j].Y)), {i, j}});
        }
    }
    sort(edge.begin(), edge.end());
    double ans = 0;
    for(auto [dist, cur] : edge) {
        if(!isGroup(cur.X, cur.Y)) {
            ans += dist;
        }
    }
    printf("%.2f", ans);
}