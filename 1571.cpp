#include <bits/stdc++.h>
#define value first
#define index second
using namespace std;
int n, ans;
vector<int> arr;
struct segTree {
    int n;
    vector<pair<int,int>> rangeMax;
    segTree(vector<int> &array) {
        n = array.size();
        rangeMax.resize(n * 4);
        init(array, 1, 0, n - 1);
    }
    pair<int,int> init(vector<int> &array, int node, int left, int right) {
        if(left == right) return rangeMax[node] = {array[left], left};
        int mid = (left + right) / 2;
        pair<int,int> l = init(array, node * 2, left, mid);
        pair<int,int> r = init(array, node * 2 + 1, mid + 1, right);
        return rangeMax[node] = max(l, r);
    }
    pair<int,int> qurey() {
        auto temp = rangeMax[1];
        update(temp.index, 1, 0, n - 1);
        return temp;
    }
    pair<int,int> update(int index, int node, int left, int right) {
        if(index < left || index > right) return rangeMax[node];
        if(index == left && left == right) return rangeMax[node] = {-1, -1};
        int mid = (left + right) / 2;
        auto l = update(index, node * 2, left, mid);
        auto r = update(index, node * 2 + 1, mid + 1, right);
        return rangeMax[node] = max(l, r);
    }
};
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    segTree st(arr);
    int e = n - 1;
    while(e != 0) {
        auto q = st.qurey();
        int idx = q.index;
        cout << idx << " " << e << "\n";
        if(idx < e) {
            ans += e - idx;
        }
        e--;
    }
    cout << ans;
}