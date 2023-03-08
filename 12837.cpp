#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
ll n, q, seg[1000000 * 4];
ll query(int l, int r, int node, int nodeL, int nodeR) {
    if(r < nodeL || l > nodeR) return 0;
    if(l <= nodeL &&  r >= nodeR) return seg[node];
    int mid = (nodeL + nodeR) / 2;
    return query(l, r, node * 2, nodeL, mid) +
            query(l,r, node * 2 + 1, mid + 1, nodeR);
}
ll update(int idx, int nv, int node, int l, int r) {
    if(idx < l || idx > r) return seg[node];
    if(l == r) return seg[node] += nv;
    int mid = (l + r) / 2;
    seg[node] = update(idx, nv, node * 2, l, mid) +
                    update(idx, nv, node * 2 + 1, mid + 1, r);
    return seg[node];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    while(q--) {
        ll m, q, x; cin >> m >> q >> x;
        if(m == 1) {
            update(q - 1, x, 1, 0, n - 1);
        } else {
            cout << query(q - 1, x - 1, 1, 0, n - 1) << '\n';
        }
    }
}