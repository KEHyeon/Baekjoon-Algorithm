#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
using namespace std;
int n, arr[2000];
unordered_map<int, int> c;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        c[arr[i]]++;
    }
    sort(arr, arr + n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int s = arr[i];
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(arr[j] * 2 == s) {
                if(s == 0) {
                    int t = upper_bound(arr, arr + n, 0) - lower_bound(arr, arr + n, 0);
                    if(t >= 3) ans++;
                }
                else {
                    int t = upper_bound(arr, arr + n, arr[j]) - lower_bound(arr, arr + n, arr[j]);
                    if(t >= 2) ans++;
                }
                break;
            }
            else if(arr[j] == 0) {
                int t = upper_bound(arr, arr + n, s) - lower_bound(arr, arr + n, s);
                if(t >= 2) {
                    ans++;
                    break;
                }
            }
            else if(arr[j] == s) {
                if(binary_search(arr, arr + n, 0)) {
                    ans++;
                    break;
                }
            }
            else if(binary_search(arr, arr + n, s - arr[j])) {
                ans++;
                break;
            }
        }
    }
    cout << ans;
}