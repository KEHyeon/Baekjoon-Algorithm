#include <bits/stdc++.h>
using namespace std;
int ans, n, parent[50], re, root;
vector<int> child[50];
void dfs(int cur) {
	if(child[cur].size() == 0) ans++;
	if(child[cur].size() == 1 && child[cur][0] == re) ans++;
	for(auto nxt : child[cur]) {
		if(nxt == re) continue;
		dfs(nxt);
	}
}
int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> parent[i];
		if(parent[i] == -1) root = i;
		child[parent[i]].push_back(i);
	}
	cin >> re;
	if(root == re) {
		cout << 0;
		return 0;
	}
	dfs(root);
	cout << ans;
}
