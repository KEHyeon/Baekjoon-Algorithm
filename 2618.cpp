#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n, w, ans = 1000000000;
vector<pair<int,int>> aci;
int memo[1002][1002];
vector<int> path;
int getDist(int x, int y) {
    if(x == w || y == w) return 0;
    int &ret = memo[x][y];
    if(ret != -1) return ret;
    int nxt = max(x, y) + 1;
    if(y == w + 1) {
        nxt = x + 1;
    }
    ret = min(getDist(nxt, y) + abs(aci[nxt].X - aci[x].X) + abs(aci[nxt].Y - aci[x].Y),
              getDist(x, nxt) + abs(aci[nxt].X - aci[y].X) + abs(aci[nxt].Y - aci[y].Y));
    return ret;
}
void getPath(int x, int y) {
    if(x == w || y == w) {
        for(int i : path) {
            cout << i << "\n";
        }
        return;
    }
    int nxt = max(x, y) + 1;
    if(y == w + 1) {
        nxt = x + 1;
    }
    int first = getDist(nxt, y) + abs(aci[nxt].X - aci[x].X) + abs(aci[nxt].Y - aci[x].Y);
    int second = getDist(x, nxt) + abs(aci[nxt].X - aci[y].X) + abs(aci[nxt].Y - aci[y].Y);
    if(first > second) {
        path.push_back(2);
        getPath(x, nxt);
    } else {
        path.push_back(1);
        getPath(nxt, y);
    }
}
int main() {
    cin >> n >> w;
    memset(memo, -1, sizeof(memo));
    aci.push_back({0, 0});
    for(int i = 0; i < w; i++) {
        int x, y; cin >> x >> y;
        aci.push_back({x - 1, y - 1});
    }
    aci.push_back({n - 1, n - 1});
    cout << getDist(0, w + 1) << "\n";
    getPath(0, w + 1);
}
