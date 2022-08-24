#include <bits/stdc++.h>
using namespace std;
int m, n;
int  arr[1000000];

bool check(int x) {
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(arr[i] >= x) cnt += arr[i] / x;
	}
	return cnt >= m;
}
int main() {
	int mx = -1, sum = 0;
	cin >> m >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		if(mx < arr[i]) mx = arr[i];
		sum += arr[i];
	}
	if(sum < m) {
		cout << 0;
		return 0;
	}
	sort(arr, arr + n);
	int lo = 1;
	int hi = mx + 1;
	while(lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if(check(mid)) lo = mid;
		else hi = mid;
	}
	cout << lo;
}
