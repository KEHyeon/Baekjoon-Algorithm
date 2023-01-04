#include <bits/stdc++.h>
using namespace std;
int n, k, m;
long long int ans;
vector<int> bag;
priority_queue<pair<int,int>> pq;
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        pq.push({b, a});
    }
    for(int i = 0; i < k; i++) {
        int x; cin >> x;
        bag.push_back(x);
        if(m < bag[i]) m = bag[i];
    }
    sort(bag.begin(), bag.end());
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int value = cur.first;
        int heavy = cur.second;
        if(heavy > m) continue;
        int idx = lower_bound(bag.begin(), bag.end(), heavy) - bag.begin();
        bag.erase(bag.begin() + idx);
        ans += value;
    }
    cout << ans;
}