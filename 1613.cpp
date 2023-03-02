#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, k;
bool isCan[400][400];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    while(k--) {
        int a, b; cin >> a >> b;
        isCan[a - 1][b - 1] = 1;
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                isCan[i][j] |= (isCan[i][k] && isCan[k][j]);
            }
        }
    }
    int s; cin >> s;
    while(s--) {
        int a, b; cin >> a >> b;
        if(!isCan[a - 1][b - 1] && !isCan[b - 1][a - 1]) cout << 0 << '\n';
        else cout << (isCan[a - 1][b - 1] ? -1 : 1) << '\n';
    }
}