#include <bits/stdc++.h>
using namespace std;
int tri[31][31];
int main() {
    for(int i = 1; i <= 30; i++) {
        for(int j = 1; j <= i; j++) {
            if(j == 1 || i == j) tri[i][j] = 1;
            else tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
        }
    }
    int r, c, w;
    cin >> r >> c >> w;
    int ans = 0;
    for(int i = r; i < r + w; i++) {
        for(int j = c; j <= c + w - (r + w - i); j++) {
            ans += tri[i][j];
        }
    }
    cout << ans;
}