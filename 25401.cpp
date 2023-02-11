#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, arr[500], ans = 123456789;
int check(int a, int b) {
    int d = (arr[b] - arr[a]) / (b - a);
    if(arr[a] + d * (b - a) != arr[b]) return INT_MAX;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] != arr[a] + d * (i - a)) cnt++;
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    int ans = 12345;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            ans = min(ans, check(i, j));
        }
    }
    cout << ans;
}