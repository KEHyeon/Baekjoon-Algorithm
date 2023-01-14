#include <bits/stdc++.h>
using namespace std;
int arr[1025][1025];
int sum[1025][1025];
int n, m;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int x; cin >> x;
            arr[i][j] = arr[i][j - 1] + x;
            sum[i][j] = sum[i - 1][j] + arr[i][j];
        }
    }
    while(m--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << '\n';

    }
}
