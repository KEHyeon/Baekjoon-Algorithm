#include <bits/stdc++.h>
using namespace std;
int n, sum;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		pq.push(x);
	}
	while(1) {
		if(pq.size() == 1) break;
		int x = pq.top(); pq.pop();
		int y = pq.top(); pq.pop();
		sum += x + y;
		pq.push(x + y);
	}
	cout << sum;
}
