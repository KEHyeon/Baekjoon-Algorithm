#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, m, house, company;
int newa[2], newb[2], newc[2];
const int INF = 123456789;
vector<pair<int,int>> graph[301];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int dist[301];
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> house >> company;
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }
    int tc; cin >> tc;
    while(tc--) {
        for(int i = 0; i <= n; i++) dist[i] = INF;
        cin >> newa[0] >> newb[0] >> newc[0];
        cin >> newa[1] >> newb[1] >> newc[1];
        dist[house] = 0;
        pq.push({0, house});
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int curNode = cur.Y;
            int curCost = cur.X;
            if(dist[curNode] < curCost) continue;
            for(auto nxt : graph[curNode]) {
                int nxtNode = nxt.Y;
                int nxtCost = nxt.X + curCost;
                if(nxtCost >= dist[nxtNode]) continue;
                dist[nxtNode] = nxtCost;
                pq.push({nxtCost, nxtNode});
            }
            //새로운 도로에 대해서 진행
            for(int i = 0; i < 2; i++) {
                if(newa[i] == curNode) {
                    int nxtNode = newb[i];
                    int nxtCost = newc[i] + curCost;
                    if(nxtCost >= dist[nxtNode]) continue;
                    dist[nxtNode] = nxtCost;
                    pq.push({nxtCost, nxtNode});
                }
            }
        }
        cout << (dist[company] == INF ? -1 : dist[company]) << '\n';
    }
}