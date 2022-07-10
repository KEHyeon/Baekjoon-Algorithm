#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
string a;
string b;
int main() {
	cin >> a >> b;
	int alen = a.size();
	int blen = b.size();
	a = '0' + a;
	b = '0' + b;
	for(int i = 0; i <= alen; i++) {
		for(int j = 0; j <= blen; j++) {
			if(i == 0 || j == 0) {
				dp[i][j] = 0;
				continue;
			}
			if(a[i] == b[j]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			}
		}
	}
	cout << dp[alen][blen];
}
