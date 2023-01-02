#include <bits/stdc++.h>
using namespace std;
long long int n, ans;
long long int arr[100000];
void f(int s, int e) {
    if(s == e)  {
        ans = max(ans, arr[s]);
        return;
    }
    int mid = (s + e) / 2;
    long long l = mid, r = mid, h = arr[mid];
    ans = max(ans, arr[mid]);
    while(s < l || r < e) {
        int left = s < l ? min(h, arr[l - 1]) : -1;
        int right = r < e ? min(h, arr[r + 1]) : -1;
        if(left > right) {
            h = left;
            l--;
        }
        else {
            h = right;
            r++;
        }
        ans = max(ans, h * (r - l + 1));
    }
    f(s, mid);
    if(s + 1 != e) {
        f(mid, e);
    } else {
        ans = max(ans, arr[e]);
    }
}
int main() {
    while(1) {
        cin >> n;
        ans = 0;
        if(n == 0) return 0;
        for(int i = 0; i < n; i++) cin >> arr[i];
        f(0, n - 1);
        cout << ans << "\n";
    }
}