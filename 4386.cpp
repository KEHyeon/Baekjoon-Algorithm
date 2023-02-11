#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, p[100];
pii star[100];
double ans;
vector<pair<double,pii>> edge;
int find(int a) {
    if(p[a] == a) return a;
    return p[a] = find(p[a]);
}
bool isGroup(int a, int b) {
    a = find(a); b = find(b);
    if(a == b) return 1;
    p[a] = b;
    return 0;
}
int main() {
    cin >> n;
    for(int i = 0; i < 100; i++) p[i] = i;
    for(int i = 0; i < n; i++) {
        double x, y; cin >> x >> y;
        star[i] = {x, y};
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            double dist = pow(star[i].X - star[j].X, 2)
                     + pow(star[i].Y - star[j].Y, 2);
            edge.push_back({sqrt(dist), {i, j}});
        }
    }
    sort(edge.begin(), edge.end());
    for(auto [dist, e] : edge) {
        if(!isGroup(e.X, e.Y)) {
            ans += dist;
        }
    }
    cout << ans;
}