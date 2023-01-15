#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<long long int> arr;
struct prefix{
    int n;
    vector<long long int> rangeSum;
    prefix(vector<long long int> &array) {
        n = array.size();
        rangeSum.resize(4 * n);
        init(array, 1, 0, n - 1);
    }
    long long int init(vector<long long int> &array, int node, int left, int right) {
        if(left == right) return rangeSum[node] = array[left];
        int mid = (left + right) / 2;
        return rangeSum[node] = init(array, node * 2, left, mid) +
                init(array, node * 2 + 1, mid + 1, right);
    }
    long long int query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }
    long long int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(left > nodeRight || right < nodeLeft) return 0;
        if(left <= nodeLeft && right >= nodeRight) return rangeSum[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return query(left, right, node * 2, nodeLeft, mid) +
                query(left, right, node *2 + 1, mid + 1, nodeRight);
    }
    void update(int index, long long int newValue) {
        update(index, newValue, 1, 0, n - 1);
    }
    long long int update(int index, long long int newValue, int node, int nodeLeft, int nodeRight) {
        if(index < nodeLeft || index > nodeRight) return query(nodeLeft, nodeRight);
        if(nodeLeft == nodeRight) return rangeSum[node] = newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeSum[node] = update(index, newValue, node * 2, nodeLeft, mid) +
                                update(index, newValue, node * 2 + 1, mid + 1, nodeRight);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        long long int x; cin >> x;
        arr.push_back(x);
    }
    prefix st(arr);
    for(int i = 0; i < m + k; i++) {
        long long int a, b, c; cin >> a >> b >> c;
        if(a == 2) {
             cout << st.query(b - 1, c - 1) << "\n";
        } else {
            st.update(b - 1, c);
        }
    }
}