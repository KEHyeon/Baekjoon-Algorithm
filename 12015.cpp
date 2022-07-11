#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ans;
int arr[1000000];
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	ans.push_back(arr[0]);
	for(int i = 1; i < n; i++) {
		if(arr[i] > ans[ans.size() - 1]) ans.push_back(arr[i]);
		else {
			*(lower_bound(ans.begin(), ans.end(), arr[i])) = arr[i];
		}
	}
	cout << ans.size();
}
