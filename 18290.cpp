#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, k, arr[10][10], ans = -100000000, vis[10][10];
vector<int> per;
void bt(int num) {
	if(per.size() == k) {
		int sum = 0;
		for(auto i : per) {
			sum += arr[i / m][i % m];
		}
		ans = max(ans, sum);
		return;
	}
	for(int i = num; i < n * m; i++) {
		if(per.size() != 0) {
			int flag = 0;
			for(int j = 0; j < 4; j++) {
				int fx = i / m + dx[j];
				int fy = i % m + dy[j];
				if(fx < 0 || fy < 0 || fx >= n || fy >= m) continue;
				if(vis[fx][fy]) {
					flag = 1;
					break;
				}
			}
			if(flag) continue;
		}

		per.push_back(i);
		vis[i / m][i % m] = 1;
		bt(i + 1);
		per.pop_back();
		vis[i / m][i % m] = 0;
	}
}
int main() {
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		for(int j = 0;j < m; j++) {
			cin >> arr[i][j];
		}
	}
	bt(0);
 	cout << ans;
}
