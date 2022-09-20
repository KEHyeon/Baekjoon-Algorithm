#include <bits/stdc++.h>
using namespace std;
long long int n, ans;
int main() {
	int tc; cin >> tc;
	while(tc--) {
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			ans+=(n/i)*i;
		}
		cout << ans << '\n';
	}
}
