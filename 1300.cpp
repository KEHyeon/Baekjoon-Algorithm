#include <bits/stdc++.h>
using namespace std;
long long n, k;
bool check(long long x) {
	long long cnt = 0;
	for(long long i = 1; i <= n; i++) cnt += min(x / i, n);
	return cnt >= k;
}
int main() {
	cin >> n >> k;
	long long lo = 0;
	long long hi = n * n;
	while(lo + 1 < hi) {
		long long mid = (lo + hi) / 2;
		if(check(mid)) hi = mid;
		else lo = mid;
	}
	cout << hi;
}
