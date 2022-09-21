#include <bits/stdc++.h>
using namespace std;
int n, arr[13];
vector<int> per;
void bt(int num) {
	if(per.size() == 6) {
		for(int i = 0; i < 6; i++) {
			cout << per[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i = num; i < n; i++) {
		per.push_back(arr[i]);
		bt(i + 1);
		per.pop_back();
	}
}
int main() {
	while(1) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		if(n == 0) return 0;
		bt(0);
		cout << "\n";
	}
}
