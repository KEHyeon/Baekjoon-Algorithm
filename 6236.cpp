#include <bits/stdc++.h>
using namespace std;
int n, m, sum;
int arr[100000];
bool check(int x) {
	int cnt = 0, use = 0;
	for(int i = 0; i < n; i++) {
		use += arr[i];
		if(use == x) {
			cnt++;
			use = 0;
		}
		else if(use > x) {
			cnt++;
			use = arr[i];
		}
	}
	if(use != 0) cnt++;
	return cnt <= m;
}
int main() {
	int mx = -1;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		if(mx < arr[i]) mx = arr[i];
		sum += arr[i];
	}
	for(int i = 1; i<= 1000; i++) {
		cout << i <<  " " << check(i) << endl;
	}
	int lo = mx - 1;
	int hi = sum;
	while(lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if(check(mid)) hi = mid;
		else lo = mid;
	}
	cout << hi;
}
