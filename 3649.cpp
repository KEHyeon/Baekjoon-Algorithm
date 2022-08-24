#include <bits/stdc++.h>
using namespace std;
int x, n;
int arr[1000000];

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(cin >> x >> n) {
		int ans1 = 0, ans2 = 0;
		bool flag = 0;
		x = x * 1e7;
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		for(int i = 0; i < n; i++) {
			int first = arr[i];
			int second = x - arr[i];
			if(binary_search(arr,arr+n,second)) {
				flag = 1;
				cout << "yes " << ans1 << " " << ans2 << "\n";
				break;
			}
		}
		if(flag)cout << "danger\n";
	}
}

