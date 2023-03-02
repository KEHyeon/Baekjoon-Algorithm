#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
vector<pii> arr[11];
int vis[11], ans;
int bt(int d) {
    if(d == 11) return 0;
    int ret = 0;
    for(auto p : arr[d]) {
        if(vis[p.Y]) continue;
        vis[p.Y] = 1;
        ret = max(ret, p.X + bt(d + 1));
        vis[p.Y] = 0;
    }
    if(ret == 0) return -12345678;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        for(int i = 0; i < 11; i++) arr[i].clear();
        for(int i = 0; i < 11; i++) {
            for(int j = 0; j < 11; j++) {
                int x; cin >> x;
                if(x != 0) arr[i].push_back({x, j});
            }
        }
        cout << bt(0) << '\n';
    }
}