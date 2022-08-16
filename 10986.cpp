#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
int arr[1000001];
long long ps[1000001];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> arr[i];
		for(int j = 1;  j <= i; j++) {
			ps[j] = ps[j] + arr[i];
			if(ps[j] % m == 0) ans++;
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << ps[i] << " ";
	}
	cout << ans;
}
