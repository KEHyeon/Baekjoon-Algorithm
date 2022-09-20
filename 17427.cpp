#include <bits/stdc++.h>
using namespace std;
long long int n, ans;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; i * j <= n; j++) {
			ans += i;
		}
	}
	cout << ans;
}
