#include <bits/stdc++.h>
using namespace std;
bool arr[10][10];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
const int INF = 10000000;
void click(bool A[][10], int x, int y) {
	A[x][y] = !A[x][y];
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
		A[nx][ny] = !A[nx][ny];
	}
}
bool check(bool A[][10]) {
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(A[i][j] == 0) return false;
		}
	}
	return true;
}
int solve(int num) {
	if(num == 10) {
		bool arr1[10][10];
		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < 10; j++) {
				arr1[i][j] = arr[i][j];
			}
		}
		int sum = 0;
		for(int i = 1; i < 10; i++) {
			for(int j = 0; j < 10; j++) {
				if(!arr1[i - 1][j]) {
					click(arr1, i, j);
					sum++;
				}
			}
		}
		if(!check(arr1)) return INF;
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
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			char x; cin >> x;
			if(x == 'O') arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}
	int ans = solve(0);
	cout << ((ans == INF) ? -1 : ans);
}
