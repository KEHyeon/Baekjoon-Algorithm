#include <bits/stdc++.h>
using namespace std;
int n, m, fw[500][500], INF = 123456789;
int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            fw[i][j] = INF;
        }
    }
    while(m--) {
        int s, e; cin >> s >> e;
        fw[s - 1][e - 1] = 1;
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        bool flag = 1;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(fw[i][j] == INF && fw[j][i] == INF) {
                flag = 0;
                break;
            }
        }
        if(flag) ans++;
    }

    cout << ans;
}