#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	while(cin >> n) {
		unsigned long long one = 1;
		int cnt = 1;
		while(1) {
			cout << one << "\n";
			if(one % n == 0) {
				cout << cnt << '\n';
				break;
			}
			cnt++;
			one = one * 10 + 1;
		}
	}
}
