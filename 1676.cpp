#include <bits/stdc++.h>
using namespace std;
int n;
int two;
int five;
int main() {
	cin >> n;
	for(int i = 2; i <= n; i++) {
		int x = i;
		while(!(x % 5 && x % 2)) {
			if(x % 5 == 0) {
				x /= 5;
				five++;
			}
			if(x % 2 == 0) {
				x /= 2;
				two++;
			}
		}
	}
	cout << min(two, five);
}
