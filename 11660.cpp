#include <bits/stdc++.h>
using namespace std;
int n, m, x1, y1, x2, y2;
int arr[1025][1025];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int num; cin >> num;
			if(j == 1) arr[i][j] = num + arr[i-1][n];
			else arr[i][j] = num + arr[i][j - 1];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	while(m--) {
		cin >> x1 >> y1 >> x2 >> y2;
		if(y1 == 1) {
			x1 -= 1;
			y1 = n;
		}
		cout << arr[x2][y2] - arr[x1][y1 - 1] << '\n';
	}
}
