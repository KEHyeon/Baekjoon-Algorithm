#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n, k;
int dist[200001];
int main() {
    cin >> n >> k;
    for(int i = 0; i < 200001; i++) dist[i] = 123456;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, n});
    while(!pq.empty()) {
        auto [cost, cur] = pq.top(); pq.pop();
        if(dist[cur] < cost) continue;
        if(cur == k) {
            cout << cost;
            return 0;
        }
        if(cur + 1 <= 200000 && dist[cur + 1] > cost + 1)  {
            dist[cur + 1] = cost + 1;
            pq.push({cost + 1, cur + 1});
        }
        if(cur - 1 >= 0 && dist[cur - 1] > cost + 1)  {
            dist[cur - 1] = cost + 1;
            pq.push({cost + 1, cur - 1});
        }
        if(cur * 2 <= 200000 && dist[cur * 2] > cost) {
            dist[cur * 2] = cost;
            pq.push({cost, cur * 2});
        }
    }
}