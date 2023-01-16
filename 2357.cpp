#include <bits/stdc++.h>
using namespace std;
int n, query;
vector<int> arr;
struct RMQ{
    int n;
    vector<pair<int,int>> rangeAns;
    RMQ(vector<int> &array) {
        n = array.size();
        rangeAns.resize(n * 4);
        init(array, 1, 0, n - 1);
    }
    pair<int,int> init(vector<int> &array, int node, int left, int right) {
        if(left == right) return rangeAns[node] = {array[left], array[left]};
        int mid = (left + right) / 2;
        auto l = init(array, node * 2, left, mid);
        auto r = init(array, node * 2 + 1, mid + 1, right);
        return rangeAns[node] = {min(l.first, r.first), max(l.second, r.second)};
    }
    pair<int,int> query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }
    pair<int,int> query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(left > nodeRight || right < nodeLeft) return {INT_MAX, INT_MIN};
        if(left <= nodeLeft && right >= nodeRight) return rangeAns[node];
        int mid = (nodeLeft + nodeRight) / 2;
        auto l = query(left, right, node * 2, nodeLeft, mid);
        auto r = query(left, right, node * 2 +  1, mid + 1, nodeRight);
        return {min(l.first, r.first), max(l.second, r.second)};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> query;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; arr.push_back(x);
    }
    RMQ st(arr);
    while (query--) {
        int a, b; cin >> a >> b;
        auto ans = st.query(a - 1, b - 1);
        cout << ans.first << " " << ans.second << "\n";
    }
}