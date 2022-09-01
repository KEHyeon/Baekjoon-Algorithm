#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> tree[10001];
int a, ans, d[10001];
int main() {
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int a, b, v; cin >> a >> b >> v;
		tree[a].push_back({b, v});
		tree[b].push_back({a, v});
	}
	queue<int> Q;
	Q.push(1);
	int mx = 0;
	d[1] = 1;
	while(!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for(auto nxt : tree[cur]) {
			if(d[nxt.first] || nxt.first == 0) continue;
			Q.push(nxt.first);
			d[nxt.first] = d[cur] + nxt.second;
			if(mx < d[nxt.first]) {
				mx = d[nxt.first];
				a = nxt.first;
			}
		}
	}
	for(int i = 0; i <= n; i++) {
		d[i] = 0;
	}
	Q.push(a);
	while(!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for(auto nxt : tree[cur]) {
			if(nxt.first == a || d[nxt.first] || nxt.first == 0) continue;
			Q.push(nxt.first);
			d[nxt.first] = d[cur] + nxt.second;
			if(ans < d[nxt.first]) {
				ans = d[nxt.first];
			}
		}
	}
	cout << ans;
}
