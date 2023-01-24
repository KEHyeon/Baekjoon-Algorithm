#include <bits/stdc++.h>
using namespace std;
int m, n, ans;
vector<pair<int,int>> space[100];
int vis[1000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
        memset(vis, 0, sizeof(vis));
        for(int j = 0; j < n; j++) {
            int x; cin >> x;
            if(vis[x]) {
                space[i].push_back({x, vis[x]});
                continue;
            }
            space[i].push_back({x, j});
            vis[x] = j;
        }
        sort(space[i].begin(), space[i].end());
    }
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            bool flag = 1;
            for(int k = 0; k < n; k++) {
                if(space[i][k].second != space[j][k].second) {
                    flag = 0;
                    break;
                }
            }
            if(flag) ans++;
        }
    }
    cout << ans;
}