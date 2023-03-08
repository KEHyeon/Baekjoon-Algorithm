#include <bits/stdc++.h>
using namespace std;
int n, arr[100000], seg[400000];

int init(int l, int r, int node) {
    if(l == r) return seg[node] = 1;
    int mid = (l + r) / 2;
    seg[node] = init(l, mid, node * 2) +
                init(mid + 1, r, node * 2 + 1);
    return seg[node];
}
int query(int l, int r, int node, int nl, int nr) {
    if(r < nl || l > nr) return 0;
    if(l <= nl && r >= nr) return seg[node];
    int mid = (nl + nr) / 2;
    seg[node] = query(l, r, node * 2, nl, mid) +
                query(l, r, node * 2 + 1, mid + 1, nr);
    return seg[node];
}
int update(int idx, int node, int l, int r) {
    if(idx < l || idx > r) return seg[node];
    if(l == r) {
        return seg[node] = 0;
    }
    int mid = (l + r) / 2;
    seg[node] = update(idx, node * 2, l, mid) +
                update(idx, node * 2 + 1, mid + 1, r);
    return seg[node];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        arr[x - 1] = i;
    }
    init(0, n - 1, 1);
    int l = 0, r = n - 1;
    for(int i = 1; i <= n; i++) {
        if(i % 2) {
            cout << query(0, arr[l], 1, 0, n - 1) - 1 << "\n";
            update(arr[l], 1, 0, n - 1);
            l++;
        } else {
            cout << query(arr[r], n - 1, 1, 0, n - 1) - 1 << "\n";
            update(arr[r], 1, 0, n - 1);
            r--;
        }
    }
}