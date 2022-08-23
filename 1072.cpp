#include <bits/stdc++.h>
using namespace std;
int x, y, rate;
bool check(long long int num) {
	return rate < (int)((double)(y + num) / (x + num) * 100);
}
int main() {
	cin >> x >> y;
	rate = (double)(y) / x  * 100;
	if(rate == 99 || rate == 100) {
		cout << -1;
		return 0;
	}
	int lo = -1;
	int hi = 1000000000;
	while(lo + 1 < hi) {
 		long long int mid = (lo + hi) / 2;
		if(check(mid)) hi = mid;
		else lo = mid;
	}
	cout << hi;
}
