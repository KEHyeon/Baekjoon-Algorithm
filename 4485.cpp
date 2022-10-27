#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int cost[125][125];
int dist[125][125];
const int inf = 99999999;
int solve() {
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({cost[0][0],{0,0}});
    dist[0][0] = cost[0][0];
    while(!pq.empty()) {
        auto cur = pq.top().Y;
        int curCost = pq.top().X; pq.pop();
        if(cur.X == n - 1 && cur.Y == n - 1) return curCost;
        if(dist[cur.X][cur.Y] < curCost) continue;
        for(int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            int nxtCost = curCost + cost[nx][ny];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(nxtCost >= dist[nx][ny]) continue;
            dist[nx][ny] = nxtCost;
            pq.push({nxtCost, {nx,ny}});
        }
    }
}
int main() {
    int cnt = 1;
    while(1) {
        cin >> n;
        if(!n) break;
        cout << "Problem " << cnt++ << ": ";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = inf;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> cost[i][j];
            }
        }
        cout << solve() << '\n';
    }
}