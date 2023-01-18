#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1000000007;
vector<ll> arr;
struct segTree {
    ll n;
    vector<ll> rangeMul;
    segTree(vector<ll> &array) {
        n = array.size();
        rangeMul.resize(n * 4);
        init(array, 1, 0, n - 1);
    }
    ll init(vector<ll> &array, int node, int left, int right) {
        if(left == right) return rangeMul[node] = array[left];
        int mid = (left + right) / 2;
        ll l = init(array, node * 2, left, mid);
        ll r = init(array, node * 2 + 1, mid + 1, right);
        return rangeMul[node] = (l * r * 1ll) % mod;
    }
    ll query(int left, int right) {
        return query(left, right, 1, 0, n -1);
    }
    ll query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(left > nodeRight || right < nodeLeft) return 1;
        if(left <= nodeLeft && right >= nodeRight) return rangeMul[node];
        ll mid = (nodeLeft + nodeRight) / 2;
        ll l = query(left, right, node * 2, nodeLeft, mid);
        ll r = query(left, right, node * 2 + 1, mid + 1, nodeRight);
        return (l * r * 1ll) % mod;
    }
    void update(int idx, int newValue) {
        update(idx, newValue, 1, 0, n - 1);
    }
    ll update(int idx, int newValue, int node, int left, int right) {
        if(left > idx || right < idx) return rangeMul[node];
        if(idx == left && left == right) return rangeMul[node] = newValue;
        ll mid = (left + right) / 2;
        ll l = update(idx, newValue,node * 2, left, mid);
        ll r = update(idx, newValue, node * 2 + 1, mid + 1, right);
        return rangeMul[node] = (l * r * 1ll) % mod;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        arr.push_back(x);
    }
    segTree st(arr);
    for(int i = 0; i < m + k; i++) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 1) {
            st.update(b - 1, c);
        }
        else cout << st.query(b - 1, c - 1) << "\n";
    }
}