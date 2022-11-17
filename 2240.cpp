#include <bits/stdc++.h>
using namespace std;

int t, w;
int tree[1001];
int memo[1001][31];

int solve(int time, int cnt) {
    if(cnt < 0) return 0;
    if(time == 0) {
        if(cnt % 2 == 0) {
            return tree[0] == 1;
        }
        if(cnt % 2 == 1) {
            return tree[0] == 2;
        }
    }
    int &ret = memo[time][cnt];
    if(ret != -1) return ret;
    int nowTree = cnt % 2 == 1 ? 2 : 1;
    ret = (tree[time] == nowTree);
    ret += max(solve(time - 1, cnt), solve(time - 1, cnt - 1));
    return ret;
}
int main() {
    cin >> t >> w;
    for(int i = 0; i < t; i++) cin >> tree[i];
    memset(memo, -1, sizeof(memo));
    cout << max(solve(t - 1, w), solve(t - 1, w - 1));
}