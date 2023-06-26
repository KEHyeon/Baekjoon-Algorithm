#include <bits/stdc++.h>
using namespace std;
int v, e, INF = 123456789;
int fw[400][400];
int main(){
    cin >> v >> e;
    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++) fw[i][j] = INF;


    while(e--) {
        int s, e, x; cin >> s >> e >> x;
        fw[s - 1][e - 1] = x;
    }

    for(int k = 0; k < v; k++) {
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(fw[i][j] != INF && fw[j][i] != INF) {
                ans = min(ans, fw[i][j] + fw[j][i]);
            }
        }
    }
    cout << (ans == INF ? -1 : ans);
}