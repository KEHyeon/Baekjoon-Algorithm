#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int main() {
	int n; cin >> n;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		arr.push_back(x);
	}
	for(int i = 1; i < n; i++) {
		if(!arr[i]) continue;
		int dis = arr[i] - 1;
		for(int j = i + 1; j < n; j++) {
			if(arr[j] % dis == 1) arr[j] = 0;
		}
		cnt++;
	}
	cout << cnt;
}
