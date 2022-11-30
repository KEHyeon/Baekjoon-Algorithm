#include <bits/stdc++.h>

using namespace std;
int n, s, e;
vector<pair<int,int>> graph[100001];
int dis[100001];
int main() {
    cin >> n >> s >> e;
    for(int i = 0; i < n - 1; i++) {
        int a, b, v; cin >> a >>  b >> v;
        graph[a].push_back(make_pair(b, v));
        graph[b].push_back(make_pair(a, v));
    }
    queue<pair<int,int>> Q;
    Q.push({s, 0});
    dis[s] = 1;
    while(!Q.empty()) {
        int cur = Q.front().first;
        int nowMax = Q.front().second; Q.pop();
        if(cur == e) {
            cout << dis[e] - 1 - nowMax;
            return 0;
        }
        for(auto nxt : graph[cur]) {
            if(dis[nxt.first]) continue;
            dis[nxt.first] = dis[cur] + nxt.second;
            Q.push({nxt.first, max(nowMax, nxt.second)});
        }
    }
}