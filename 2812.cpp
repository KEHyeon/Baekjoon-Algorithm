#include <bits/stdc++.h>
using namespace std;
int n, k;
priority_queue<pair<int,int>> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i <= k; i++) {
        char x; cin >> x;
        pq.push({(x - '0'), -i});
    }
    auto a = pq.top();
    pq.pop();
    cout << a.first;
    int idx = -a.second;
    for(int i = k + 1; i < n ; i++) {
        char x; cin >> x;
        pq.push({(x - '0'), -i});
        while(-pq.top().second < idx) {
            pq.pop();
        }
        a = pq.top(); pq.pop();
        cout << a.first;
        idx = -a.second;
    }
}