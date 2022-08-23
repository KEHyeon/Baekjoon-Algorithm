#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[100000];
bool check(int x) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum =+ arr[i] < x ? x : arr[i];
	}
	return sum <= m;
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	int lo = -1;
	int hi = m;
	while(lo + 1 < hi) {
		long long int mid = (lo + hi) / 2;
		if(check(mid)) lo = mid;
		else hi = mid;
	}
	cout << lo;
}

