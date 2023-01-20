#include <bits/stdc++.h>
using namespace std;
int t, k;
int memo[10001][100];
vector<pair<int,int>> coin;
int f(int x, int y) {
    if(x < 0) return 0;
    if(x == 0) return 1;
    if(y == k) return 0;
    int &ret = memo[x][y];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i <= coin[y].second; i++) {
        ret += f(x - coin[y].first * i, y + 1);
    }
    return ret;
}
int main() {
    memset(memo, -1, sizeof(memo));
    cin >> t >> k;
    for(int i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        coin.push_back({a, b});
    }
    cout << f(t, 0);
}