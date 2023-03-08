#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
ll n, q, arr[100000], seg[400000];
ll init(int l, int r, int node) {
    if(l == r) return seg[node] = arr[l];
    ll mid = (l + r) / 2;
    seg[node] = init(l, mid, node * 2) +
                init(mid + 1, r, node * 2 + 1);
    return seg[node];
}
ll query(int l, int r, int node, int nL, int nR) {
    if(l > nR || r < nL) return 0;
    if(l <= nL && r >= nR) return seg[node];
    ll mid = (nL + nR) / 2;
    return query(l, r, node * 2, nL, mid) +
            query(l, r, node * 2 + 1, mid + 1, nR);
}
ll update(int idx, int nv, int node, int l, int r) {
    if(idx < l || idx > r) return seg[node];
    if(l == r) return seg[node] = nv;
    ll mid = (l + r) / 2;
    seg[node] = update(idx,  nv,  node * 2, l, mid) +
            update(idx, nv, node * 2 + 1, mid + 1, r);
    return seg[node];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];
    init(0, n - 1, 1);
    while(q--) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        x--; y--; a--;
        if(x > y) swap(x, y);
        cout << query(x, y, 1, 0, n - 1) << "\n";
        update(a, b, 1, 0,n - 1);
    }
}