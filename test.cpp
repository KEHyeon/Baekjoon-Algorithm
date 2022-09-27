#include <bits/stdc++.h>
using namespace std;
long long int n, k;
bool check(long long int x) {
	long long int cnt = 0;
	for(long long int i = 1; i <= n; i++) cnt += min(x / i, n);
	cout << x << " : " << cnt << '\n'; 
	return cnt >= k;
}
int main() {
	cin >> n >> k;
	long long int lo = 1;
	long long int hi = min((long long)1000000000, n * n);
	while(lo + 1 < hi) {
		long long int mid = (lo + hi) / 2;
		if(check(mid)) hi = mid;
		else lo = mid;
	}
	cout << hi;
}
