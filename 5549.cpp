#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int jSum[1001][1001];
int oSum[1001][1001];
int iSum[1001][1001];
int jArr[1001];
int oArr[1001];
int iArr[1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char x; cin >> x;
            jArr[j] = jArr[j - 1] + (x == 'J');
            oArr[j] = oArr[j - 1] + (x == 'O');
            iArr[j] = iArr[j - 1] + (x == 'I');
            jSum[i][j] = jSum[i - 1][j] + jArr[j];
            oSum[i][j] = oSum[i - 1][j] + oArr[j];
            iSum[i][j] = iSum[i - 1][j] + iArr[j];
        }
    }
    while(k--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << jSum[x2][y2] - jSum[x1 - 1][y2] - jSum[x2][y1 - 1] + jSum[x1 - 1][y1 - 1] << " ";
        cout << oSum[x2][y2] - oSum[x1 - 1][y2] - oSum[x2][y1 - 1] + oSum[x1 - 1][y1 - 1] << " ";
        cout << iSum[x2][y2] - iSum[x1 - 1][y2] - iSum[x2][y1 - 1] + iSum[x1 - 1][y1 - 1] << "\n";
    }
}