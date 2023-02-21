#include <bits/stdc++.h>
using namespace std;
int n, c, arr[200000];
bool check(int x) {
	int cnt = 1;
	int now = arr[0];
	for(int i = 1; i < n; i++) {
		if(arr[i] - now >= x) {
			cnt++;
			now = arr[i];
		}
	}
	return cnt >= c;
}
int main() {
	cin >> n >> c;
	int lo = 1;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
    int hi = arr[n - 1] - arr[0];
	while(lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if(check(mid)) {
			hi = mid;
		}
		else hi = mid;
	}
	cout << lo;
}
