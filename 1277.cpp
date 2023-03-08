#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<double ,int>
using namespace std;
int n, w;
double m;
pair<ll,ll> c[1000];
double dist[1000];
bool isCon[1000][1000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> w >> m;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        c[i] = {a, b};
    }
    for(int i = 0; i < w; i++) {
        int a, b; cin >> a >> b;
        isCon[a - 1][b - 1] = 1;
        isCon[b - 1][a - 1] = 1;
    }
    for(int i = 0; i < n; i++) dist[i] = INT_MAX;
    priority_queue<pii> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while(!pq.empty()) {
        auto [curd, cur] = pq.top(); pq.pop();
        curd = -curd;
        if(curd > dist[cur]) continue;
        for(int i = 0; i < n; i++) {
            if(cur == i) continue;
            double nn = sqrt((c[cur].X - c[i].X) * (c[cur].X - c[i].X) + (c[cur].Y - c[i].Y) * (c[cur].Y - c[i].Y));
            if(isCon[cur][i]) nn = 0;
            if(nn > m) continue;
            if(curd + nn >= dist[i]) continue;
            dist[i] = (curd + nn);
            pq.push({-dist[i], i});
        }
    }
    cout << int(dist[n - 1] * 1000);
}