#include <bits/stdc++.h>
using namespace std;
long long int n, ans[1000001];
int arr[1000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int tc; cin >> tc;
    for(int i = 1; i < 1000001; i++) {
        for(int j = 1; i * j <= 1000001; j++) {
            arr[i * j] += i;
        }
    }
    for(int i = 1; i < 1000001; i++) ans[i] = ans[i - 1] + arr[i];
	while(tc--) {
		cin >> n;
		cout << ans[n] << '\n';
	}
}
