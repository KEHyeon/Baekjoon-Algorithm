#include <bits/stdc++.h>
using namespace std;
int n;
int arr[20][20];
int vis[20];
int sum, ans = 123123123;
void f(int num, int depth) {
	if(depth == n / 2) {
		int start = 0;
		int link = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(vis[i] && vis[j]) start += arr[i][j];
				else if(!(vis[i]||vis[j])) link += arr[i][j];
			}
		}
		if(ans > abs(start - link)) {
			ans = abs(start-link);
		}
		return;
	} 
	for(int i = num; i < n; i++) {
		vis[i] = 1;
		f(i + 1, depth + 1);
		vis[i] = 0;
		
	}
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> arr[i][j];
			sum += arr[i][j];
		}
	}
	f(0, 0);
	cout << ans;
	return 0;
}
