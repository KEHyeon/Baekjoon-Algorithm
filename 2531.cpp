#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, d, k, c, arr[3000000];
int vis[3001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d >> k >> c;
    for(int i = 0; i < n; i++) cin >> arr[i];
    int cnt = 0;
    for(int i = 0; i < k; i++) {
        if(vis[arr[i]] == 0) cnt++;
        vis[arr[i]]++;
    }
    int l = 0, r = k - 1, m = 0;
    while(1) {
        m = max(cnt + (vis[c] == 0), m);
        vis[arr[l]]--;
        if(vis[arr[l]] == 0) cnt--;
        l++; r++;
        if(l >= n) l = 0;
        if(r >= n) r = 0;
        vis[arr[r]]++;
        if(vis[arr[r]] == 1) cnt++;
        if(r == k - 1) break;
    }
    cout << m;
}