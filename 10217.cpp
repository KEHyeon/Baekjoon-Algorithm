#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<tuple<int,int,int>> graph[101];
int memo[101][10001]; //(x,y)는 현재 위치가 x이고 y원 남았을때 최소 비용
int dp(int x, int y) {
    if(y > m) return 123456789;
    if(x == n) return 0;
    int &ret = memo[x][y];
    if(ret != 0) return ret;
    ret = 123456789;
    for(auto nxt : graph[x]) {
        auto [nxtNode, cost , time] = nxt;
        ret = min(ret, dp(nxtNode, y + cost) + time);
    }
    return ret;
}
int main() {
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m >> k;
        for(int i = 0; i <= n; i++){
            graph[i].clear();
        }
        memset(memo, 0, sizeof(memo));
        for(int i = 0; i < n; i++) {
            int a, b, c, d; cin >> a >> b >> c >> d;
             graph[a].push_back({b, c, d});
        }
        if(dp(1, 0) == 123456789) cout << "Poor KCM\n";
        else cout << dp(1, 0) << "\n";
    }
}