#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> arr;
struct RMQ {
    int n;
    vector<int> rangeMin;
    RMQ(const vector<int>& array) {
        n = array.size();
        rangeMin.resize(n * 4);
        init(array, 0, n-1,1);
    }
    int init(const vector<int>& array, int left, int right, int node) {
        if(left == right)
            return rangeMin[node] = array[left];
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node * 2);
        int rightMin = init(array, mid + 1, right, node * 2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }
    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || left > nodeRight) return INT_MAX;
        if(left <= nodeLeft && right >= nodeRight)
            return rangeMin[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node * 2, nodeLeft, mid),
                   query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }
    int query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    RMQ st(arr);
    while(m--) {
        int a, b; cin >> a >> b;
        cout << st.query(a - 1, b - 1) << "\n";
    }
}