#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int arr[100000];
int main() {
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m >> k;
        for(int i = 0; i < n; i++) cin >> arr[i];
        int p1 = 0, p2 = m - 1, sum = 0, cnt = 0;
        for(int i = 0; i < m; i++) sum += arr[i];
        while(1) {
            if(sum < k) cnt++;
            if(m == n) break;
            sum -= arr[p1];
            if(p1 + 1 == n) p1 = 0;
            else p1++;
            if(p2 + 1 == n) p2 = 0;
            else p2++;
            sum += arr[p2];
            if(p1 == 0) break;
        }
        cout << cnt << '\n';
    }
}