#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> graph[50001];
int parent[50001], level[50001];
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void set_tree(int cur, int l) {
	level[cur] = l;
	for(int nxt : graph[cur]) {
		if(parent[nxt]) continue;
		parent[nxt] = cur;
		set_tree(nxt, l + 1);
	}
}
int lca(int a, int b) {
	if(level[a] > level[b]) swap(a, b);
	while(level[a] != level[b]) {
		b = parent[b];
	}
	while(a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
} 
int main() {
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}	
	parent[1] = 1;
	set_tree(1, 0);
	cin >> m;
	while(m--) {
		int a, b; cin >> a >> b;
		cout << lca(a, b) << "\n";
	}	
}
