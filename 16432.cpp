#include <bits/stdc++.h>
using namespace std;
int n;
bool graph[1001][10];
int memo[1001][10];//(x,y) x번쨋날에 y번째 떡을 팔았을떄 가능 여부
int dfs(int x, int y) {
    if(x == n) return 1;
    int &ret = memo[x][y];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 1; i <= 9; i++) {
        if(!graph[x + 1][i] || i == y) continue;
        ret |= dfs(x + 1, i);
    }
    return ret;
}
void backTracking(int x, int y) {
    if(x == n) return;
    for(int i = 1; i <= 9; i++) {
        if(!graph[x + 1][i] || i == y) continue;
        if(dfs(x + 1, i)) {
            cout << i << '\n';
            backTracking(x + 1, i);
            return;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(memo, -1, sizeof(memo));
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int m; cin >> m;
        while(m--) {
            int a; cin >> a;
            graph[i][a] = 1;
        }
    }
    if(!dfs(0, 0)) cout << -1;
    else {
        backTracking(0, 0);
    }
}