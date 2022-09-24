#include <bits/stdc++.h>
using namespace std;
int n, m, arr[8], vis[8];
vector<int> per;
void f() {
	if(per.size() == m) {
		for(auto i : per) cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	for(int i = 0; i < n; i++) {
		per.push_back(i);
		f();
		per.pop_back();
	}
}
int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	f();
}  
