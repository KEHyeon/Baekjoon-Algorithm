#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n;
vector<int> a, b;
pair<int,int> dp[10000][2]; // 가로길이
pair<int,int> f(int num, bool o) { // o가 1이면 가로가 a 0이면 b
    if(num == 0) return o ? make_pair(a[num], b[num]) : make_pair(b[num], a[num]);
    auto &ret = dp[num][o];
    if(ret.X) return ret;
    ret = {0, 0};
    int g = (o ? a[num] : b[num]), s = (o ? b[num] : a[num]);
    int temp  = -1;
    for(int i = 0; i < num; i++) {
        if((f(i, 0).X + g) * min(s, f(i, 0).Y) > temp) {
            ret = {f(i, 0).X + g, min(s, f(i, 0).Y)};
            temp = (f(i, 0).X + g) * min(s, f(i, 0).Y);
        }
        if((f(i, 1).X + g) * min(s, f(i, 1).Y) > temp) {
            ret = {f(i, 1).X + g, min(s, f(i, 1).Y)};
            temp = (f(i, 1).X + g) * min(s, f(i, 1).Y);
        }
    }
    return ret;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) { int x; cin >> x; a.push_back(x); };
    for(int i = 0; i < n; i++) { int x; cin >> x; b.push_back(x); };
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            ans = max(ans, f(i, j).X * f(i,j).Y);
        }
    }
    cout << ans;
}