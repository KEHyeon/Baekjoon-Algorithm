#include <bits/stdc++.h>
using namespace std;
int n, m;
int memo[201][201];
int f(int n, int k) {
	if(n == 1 || k == 1) return 1;
	if(memo[n][k]) return memo[n][k];
	if(n <= k) return memo[n][k] = f(n, k-1) + n;
	return memo[n][k] = f(n - 1, k) + f(n, k - 1);
}
int main() {
	cin >> n >> m;
	cout << f(n, m);
}
