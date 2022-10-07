#include <bits/stdc++.h>
using namespace std;
int n, m, h;
int linked[31][11];
const int INF = 123456789;

bool check() {
	for(int i = 1; i <= n; i++) {
		int cur = i;
		for(int j = 1; j <= h; j++) {
			if(linked[j][cur]) {
				cur += 1;
			}
			else if(linked[j][cur - 1]) {
				cur -= 1;
			}
		}
		if(cur != i) return false;
	}
	return true;
}

int solve(int num, int x, int y) {
	if(check()) return 0;
	if(num == 3) {
		return INF;
	}
	int ret = INF;
	for(int i = x; i <= n - 1; i++) {
		for(int j = (i == x) ? y : 1; j <= h; j++) {
			if(linked[j][i - 1] || linked[j][i + 1] || linked[j][i]) continue;
			linked[j][i] = 1;
			ret = min(ret, 1 + solve(num + 1, i, j + 1));
			linked[j][i] = 0;
		}
	}
	return ret;
}
int main() {
	cin >> n >> m >> h;
	while(m--) {
		int a, b; cin >> a >> b;
		linked[a][b] = 1;
	}
	int ans = solve(0, 1, 1);
	cout << ((ans == INF) ? -1 : ans);
}
