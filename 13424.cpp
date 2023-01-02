#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int dist[101][101];
vector<int> fr;
int main() {
    int tc; cin >> tc;
    while(tc--) {
        fr.clear();
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i == j) dist[i][j] = 0;
                else dist[i][j] = 12345689;
            }
        }
        for(int i = 0; i < m; i++) {
            int a, b, c; cin >> a >> b >> c;
            dist[a][b] = c;
            dist[b][a] = c;
        }
        for(int k = 1; k <= n; k++) {
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        cin >> k;
        for(int i = 0; i < k; i++) {
            int x; cin >> x;
            fr.push_back(x);
        }
        int MIN = 123456789;
        int ans;
        for(int i = 1; i <= n; i++) {
            int sum = 0;
            for(int j = 0; j < k; j++) {
                sum += dist[fr[j]][i];
            }
            if(sum < MIN) {
                MIN = sum;
                ans = i;
            }
        }
        cout << ans << "\n";
    }
}