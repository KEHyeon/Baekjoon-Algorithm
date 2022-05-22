#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int arr[200000];
int cnt[100001];
int n, k, ans;
int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> arr[i];
	int pt1 = 0;
	int pt2 = 0;
	cnt[arr[0]]++;
	while(pt2 < n - 1) {
		pt2++;
		cnt[arr[pt2]]++;
		if(cnt[arr[pt2]] > k) {
			while(cnt[arr[pt2]] != k) {
				cnt[arr[pt1]]--;
				pt1++;
			}
		}
		if(ans < pt2 - pt1) {
			ans = pt2 - pt1; 
		}
	}
	cout << ans + 1;
}

