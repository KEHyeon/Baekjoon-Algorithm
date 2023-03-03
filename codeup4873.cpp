#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
pair<int,int> arr[26];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        memset(arr, 0, sizeof(arr));
        int n, k; cin >> n >> k;
        string str; cin >> str;
        for(char i : str) {
            if(i >= 'a') arr[i - 'a'].X++;
            else arr[i - 'A'].Y++;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            ans += min(arr[i].X, arr[i].Y);
            int a = abs(arr[i].X - arr[i].Y);
            if(k > a / 2) {
                ans += a / 2;
                k -= a / 2;
            } else {
                ans += k;
                k = 0;
            }
        }
        cout << ans << "\n";
    }
}