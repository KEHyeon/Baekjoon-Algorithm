#include <bits/stdc++.h>
using namespace std;
bool arr[18][18];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int n;
const int INF = 10000000;
void click(bool A[][18], int x, int y) {
	A[x][y] = !A[x][y];
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		A[nx][ny] = !A[nx][ny];
	}
}
int solve(int num) {
	if(num == n) {
		bool arr1[18][18];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				arr1[i][j] = arr[i][j];
			}
		}
		int sum = 0;
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(!arr1[i - 1][j]) {
					click(arr1, i, j);
					sum++;
				}
			}
		}
		bool ok = true;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(arr1[i][j] == 0) ok = false;
			}
			if(ok == false) break;
		}
		if(ok) return INF;
		return sum;
	}
	int ret = INF;
	ret = min(ret, solve(num + 1));
	click(arr, 0, num);
	ret = min(ret, 1 + solve(num + 1));
	click(arr, 0, num);
	return ret;
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = solve(0);
	cout << ((ans == INF) ? -1 : ans);
}
