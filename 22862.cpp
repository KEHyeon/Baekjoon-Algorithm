#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, k;
vector<int> arr(1000000);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    int l = 0, r = 0;
    int cur = 0;
    int ans = 0;
    while(r < n) {
        if(arr[r] % 2) cur++;
        ans = max(ans, r - l + 1 - cur);
        while(cur > k) {
            if(arr[l] % 2) {
                cur--;
                l++;
            }
            if(cur <= k) break;
            l++;
        }
        r++;
    }
    cout << ans;
}