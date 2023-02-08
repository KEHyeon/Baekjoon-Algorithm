#include <bits/stdc++.h>

using namespace std;
int n;
int a[20001], ans = 1;
bool vis[20001];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            int cnt = 0;
            for(int j = i; !vis[j]; j = a[j]) {
                vis[j] = 1;
                cnt++;
            }
            ans = lcm(ans, cnt);
        }
    }
    cout << ans;
}