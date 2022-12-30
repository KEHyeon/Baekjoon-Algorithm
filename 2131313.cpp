#include <bits/stdc++.h>
using namespace std;
int cnt[100001];
int main() {
    int tc; cin >> tc;
    while(tc--) {
        memset(cnt, 0, sizeof(cnt));
        long long int n; cin >> n;
        long long int MAX = -1;
        long long int MIN = 10000000;
        long long int ans;
        long long int x;
        for(int i = 0; i < n; i++) {
            cin >> x;
            cnt[x]++;
            if(MAX < x) MAX = x;
            if(MIN > x) MIN = x;
        }
        ans = cnt[MAX] * cnt[MIN] * 2;
        if(MIN == MAX)  {
            ans = cnt[MAX] * (cnt[MIN] - 1);
        }
        cout << ans << "\n";
    }
}