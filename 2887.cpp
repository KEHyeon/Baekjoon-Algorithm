#include <bits/stdc++.h>
using namespace std;

long long int n, ans, cnt;
vector<pair<int,int>> xcost;
vector<pair<int,int>> ycost;
vector<pair<int,int>> zcost;
vector<tuple<int,int,int>> edge;
vector<int> p(100001, -1);

int find(int cur) {
    if(p[cur] == -1) return cur;
    return p[cur] = find(p[cur]);
}
bool isGroup(int a, int b) {
    a = find(a); b = find(b);
    if(a == b) return 1;
    if(a < b) p[a] = b;
    else p[b] = a;
    return 0;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        xcost.push_back({x, i});
        ycost.push_back({y, i});
        zcost.push_back({z, i});
    }
    sort(xcost.begin(), xcost.end());
    sort(ycost.begin(), ycost.end());
    sort(zcost.begin(), zcost.end());
    for(int i = 0; i < n - 1; i++) {
        edge.push_back({abs(xcost[i].first - xcost[i + 1].first), xcost[i].second, xcost[i + 1].second});
        edge.push_back({abs(ycost[i].first - ycost[i + 1].first), ycost[i].second, ycost[i + 1].second});
        edge.push_back({abs(zcost[i].first - zcost[i + 1].first), zcost[i].second, zcost[i + 1].second});
    }
    sort(edge.begin(), edge.end());
    for(auto i  : edge) {
        int cost, a, b;
        tie(cost, a, b) = i;
        if(isGroup(a, b)) continue;
        ans += cost;
        cnt++;
        if(cnt == n - 1) break;
    }
    cout << ans;
}