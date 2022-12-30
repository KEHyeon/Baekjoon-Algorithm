#include <bits/stdc++.h>
using namespace std;
bool garo[10][10];
bool sero[10][10];
bool gr[10][10];
int arr[10][10];
int g;
int flag = 1;
vector < pair <pair<int,int>, int> > sdk;
void f(int n) {
    if(flag == 0) return;
    if(n == g) {
        if(flag) {
            flag = 0;
            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < 9; j++) {
                    cout << arr[i][j];
                }
                cout << "\n";
            }
        }
    }
    for(int i = 1; i <= 9; i++) {
        pair<int,int> cur = sdk[n].first;
        int group = sdk[n].second;
        if(sero[cur.first][i] || garo[cur.second][i] || gr[group][i] ) continue;
        arr[cur.first][cur.second] = i;
        sero[cur.first][i] = garo[cur.second][i] = gr[group][i] = 1;
        f(n + 1);
        sero[cur.first][i] = garo[cur.second][i] = gr[group][i] = 0;
    }
}
int main() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            int group;
            if(i < 3 && j < 3) group = 0;
            else if(i < 3 && j < 6) group = 1;
            else if(i < 3 && j < 9) group = 2;
            else if(i < 6 && j < 3) group = 3;
            else if(i < 6 && j < 6) group = 4;
            else if(i < 6 && j < 9) group = 5;
            else if(i < 9 && j < 3) group = 6;
            else if(i < 9 && j < 6) group = 7;
            else if(i < 9 && j < 9) group = 8;
            char x; cin >> x;
            arr[i][j] = x - '0';
            if(arr[i][j] == 0) {
                sdk.push_back({{i, j}, group});
                g++;
                continue;
            }
            sero[i][arr[i][j]] = 1;
            garo[j][arr[i][j]] = 1;
            gr[group][arr[i][j]] = 1;
        }
    }
    f(0);
}
