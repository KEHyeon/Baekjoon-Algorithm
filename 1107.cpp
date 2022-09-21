#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> canUse;
int cantUse[11];
int ans = 1111111111;
int baseCase = 1;
void f(int x, int num) {
	if(abs(n - x) + num < ans) {
		ans = abs(n - x) + num;
	}
	if(num == baseCase) return;
	for(int i = 0; i < canUse.size(); i++) {
		if(num == 0) {
			f(canUse[i], num + 1);
		}
		else {
			f(x * 10 + canUse[i], num + 1);
		}
	}
}
int main() {
	cin >> n >> m;
	int temp = n;
	while(temp != 0) {
		baseCase++;
		temp /= 10;
	}
	for(int i = 0; i < m; i++) {
		int x; cin >> x;
		cantUse[x] = 1;
	}
	if(n == 100) {
		cout << 0;
		return 0;
	}
	for(int i = 0; i <= 9; i++) {
		if(cantUse[i]) continue;
		canUse.push_back(i);
	}
	f(100, 0);
	cout << ans;
}
