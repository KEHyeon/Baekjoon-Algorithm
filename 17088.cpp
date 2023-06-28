#include <bits/stdc++.h>
using namespace std;
int n, arr[100000], ans = 123456789;
int first[9] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
int second[9] = {0, 1, -1, 0, 1, -1, 0, 1, -1};
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < 9; i++) {
        int a = arr[0] + first[i], b = arr[1] + second[i];
        int d = b - a, cnt = (first[i] != 0) + (second[i] != 0);
        for(int j = 2; j < n; j++) {
            int nxt = a + d * j;
            if(arr[j] + 1 == nxt || arr[j] - 1 == nxt) cnt++;
            else if(arr[j] == nxt) continue;
            else {
                cnt = 123456789;
                break;
            }
        }
        ans = min(ans, cnt);
    }
    if(ans == 123456789) cout << -1;
    else cout << ans;
}