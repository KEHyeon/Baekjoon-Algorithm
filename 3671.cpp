#include <bits/stdc++.h>
using namespace std;
bool a[10000001];
int n, cnt;
int arr[7];
bool isUsed[7];
map<int, bool> vis;
void bt(int num) {
    if(!a[num] && !vis[num]) {
        vis[num] = 1;
        cnt++;
    }
    for(int i = 0; i < n; i++) {
        if(isUsed[i]) continue;
        if(num == 0 && arr[i] == 0) continue;
        isUsed[i] = 1;
        bt(num * 10 + arr[i]);
        isUsed[i] = 0;
    }
    return;
}
int main() {
    int tc; cin >> tc;
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i < 10000000; i++) {
        if(!a[i]) {
            for(int j = 2; j * i <= 10000000; j++) {
                a[i * j] = 1;
            }
        }
    }
    while(tc--) {
        cnt = 0;
        vis.clear();
        string str; cin >> str;
        n = str.size();
        for(int i = 0; i < n; i++) arr[i] = str[i] - '0';
        bt(0);
        cout << cnt << "\n";
    }
}