#define X first
#define Y second
#include <bits/stdc++.h>
using namespace std;
int n, l, m, ans;
vector<pair<int,int>> fish;
int calc(int x, int y, int xx, int yy) {
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        if(fish[i].X >= x && fish[i].Y >= y && fish[i].X <= x + xx && fish[i].Y <= y + yy) cnt++;
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> l >> m;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        fish.push_back({a, b});
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 1; k < l / 2; k++) {
                ans = max(ans, calc(fish[i].X, fish[j].Y, k, l / 2 - k));
            }
        }
    }
    cout << ans;
}