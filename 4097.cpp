#include <bits/stdc++.h>
using namespace std;
int n;
long long int dp[250001];
int main() {
	while(cin >> n && n) {
		long long int ans = -1000000000000;
		for(int i = 1; i <= n; i++) {
			long long int x; cin >> x;
			dp[i] = max(dp[i-1] + x, x);
			if(ans < dp[i]) ans = dp[i];
		}
		cout << ans << '\n';
	}
}


