#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, c, ans;
pii farm[2000];
int parent[2000];
int find(int cur) {
    if(parent[cur] == cur) return cur;
    return parent[cur] = find(parent[cur]);
}
bool isGroup(int a, int b) {
    a = find(a); b = find(b);
    if(a == b) return 1;
    if(a > b) parent[b] = a;
    else parent[a] = b;
    return 0;
}
int main() {
    cin >> n >> c;
    for(int i = 0; i < n; i++) parent[i] = i;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        farm[i] = {a, b};
    }
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int xDist = pow(farm[i].X - farm[j].X, 2);
            int yDist = pow(farm[i].Y - farm[j].Y, 2);
            if(xDist + yDist >= c) {
                pq.push({xDist + yDist, {i, j}});
            }
        }
    }
    int cnt = 0;
    while(!pq.empty()) {
        auto temp = pq.top(); pq.pop();
        pii cur = temp.Y;
        int cost = temp.X;
        if(!isGroup(cur.X, cur.Y)) {
            cnt++;
            ans += cost;
        }
    }
    if(cnt < n - 1) cout << -1;
    else cout << ans;
}