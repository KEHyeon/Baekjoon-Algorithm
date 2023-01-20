#include <bits/stdc++.h>
using namespace std;
long long int n, m, ans;
int mod[1000001];
long long int cnt[1000];
int main() {
	cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        mod[i] = (mod[i - 1] + x) % m;
        cnt[mod[i]]++;
    }
    cnt[0]++;
    for(int i = 0; i < m; i++) {
        if(cnt[i] >= 2) {
            ans += (cnt[i] * (cnt[i] - 1)) / 2;
        }
    }
    cout << ans;
}