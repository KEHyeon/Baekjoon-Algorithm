#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[100000];
bool check(long long int x) {
	int sum = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		sum += arr[i];
		if(sum > x) {
			cnt++;
			sum = arr[i];
		}
		else if(sum == x) {
			cnt++;
			sum = 0;	
		}
	}
	if(sum < x && sum != 0) cnt++;
	return (cnt <= m);
}
int main() {
	cin >> n >> m;
	int sum = 0;
	int mx = -1;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		if(mx < arr[i]) mx = arr[i];
	}
	int lo = mx - 1;
	int hi = sum ;
	while(lo + 1 < hi) {
		long long int mid = (lo + hi) / 2;
		if(check(mid)) hi = mid;
		else lo = mid;
	}
	cout << hi;
}
