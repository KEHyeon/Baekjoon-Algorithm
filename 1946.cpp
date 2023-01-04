#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main() {
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            int a, b; cin >> a >> b;
            pq.push({a, b});
        }
        int MAX = pq.top().second;
        while(!pq.empty()) {
            int cur = pq.top().second;
            pq.pop();
            if(cur < MAX) {
                cnt++;
                MAX = cur;
            }
        }
        cout << cnt + 1 << "\n";
    }
}