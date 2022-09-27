#include <bits/stdc++.h>
using namespace std;
int n, m, arr[500][500], ans = 0;
bool check(int x, int y) {
	return (x >= 0 && y >= 0 && x < n && y < m);
}
void rotate() {
	vector<int> temp[500];
	int line = 0;
	for(int i = m - 1; i >= 0; i--) {
		for(int j = 0; j < n; j++) {
			temp[line].push_back(arr[j][i]);
		}
		line++;
	}
	int temp2 = n;
	n = m;
	m = temp2;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			arr[i][j] = temp[i][j];
		}
	}
}
int blue(int x, int y) {
	int sum = 0;
	for(int i = y; i < y + 4; i++) {
		if(!check(x, i)) return 0;
		sum += arr[x][i];
	}
	return sum;
}
int yellow(int x, int y) {
	int sum = 0;
	for(int i = x; i < x + 2; i++) {
		for(int j = y; j < y + 2; j++) {
			if(!check(i, j)) return 0;
			sum += arr[i][j];
		}
	}
	return sum;
}
int orange(int x, int y) {
	int sum = 0;
	for(int i = x; i < x + 3; i++) {
		if(!check(i, y)) return 0;
		sum += arr[i][y];
	}
	if(!check(x + 2, y + 1)) return 0;
	sum += arr[x + 2][y + 1];
	return sum;
}
int orange2(int x, int y) {
	int sum = 0;
	for(int i = x; i < x + 3; i++) {
		if(!check(i, y)) return 0;
		sum += arr[i][y];
	}
	if(!check(x + 2, y - 1)) return 0;
	sum += arr[x + 2][y - 1];
	return sum;
}
int green(int x, int y) {
	int sum = 0;
	for(int i = x; i < x + 2; i++) {
		if(!check(i, y)) return 0;
		sum += arr[i][y];
	}
	for(int i = x + 1; i < x + 3; i++) {
		if(!check(i, y + 1)) return 0;
		sum += arr[i][y + 1];
	}
	return sum;
}
int green2(int x, int y) {
	int sum = 0;
	y += 1;
	for(int i = x; i < x + 2; i++) {
		if(!check(i, y)) return 0;
		sum += arr[i][y];
	}
	for(int i = x + 1; i < x + 3; i++) {
		if(!check(i, y - 1)) return 0;
		sum += arr[i][y - 1];
	}
	return sum;
}
int pupple(int x, int y) {
	int sum = 0;
	for(int i = y; i < y + 3; i++) {
		if(!check(x, i)) return 0;
		sum += arr[x][i];
	}
	if(!check(x + 1,y + 1)) return 0;
	sum += arr[x + 1][y + 1];
	return sum;
}
void solution() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			ans = max(ans, blue(i, j));
			ans = max(ans, yellow(i, j));
			ans = max(ans, orange(i, j));
			ans = max(ans, green(i, j));
			ans = max(ans, pupple(i, j));
			ans = max(ans, orange2(i,j));
			ans = max(ans, green2(i,j));
		}
	}
	rotate();
}
int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0;j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for(int i = 0; i < 4; i++) {
		solution();
	}
	cout << ans;
}
