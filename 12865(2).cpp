#include <bits/stdc++.h>
using namespace std;
int n, k;
int weight[101];
int value[101];
int memo[101][100001];
int f(int now, int sum) {
	if(sum > k) return -123456789;
	if(now == -1) return 0;
	if(memo[now][sum]) return memo[now][sum];
	return memo[now][sum] = max(f(now - 1, sum + weight[now]) + value[now], f(now - 1, sum));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> weight[i] >> value[i];
	}
	cout << f(n - 1, 0);
}
