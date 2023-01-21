#include <bits/stdc++.h>

using namespace std;
priority_queue<pair<int,int>> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int query; cin >> query;
    while(query--) {
        int x; cin >> x;
        if(x == 0) {
            if(pq.empty()) {
                cout << 0 << '\n';
                continue;
            }
            cout << -pq.top().second << '\n';
            pq.pop();
        } else {
            pq.push({-abs(x), -x});
        }
    }
}