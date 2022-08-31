#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n;
int pre[1001];
int in[1001];
pair<int,int> tree[1001];
int getRoot(int l, int r) {
	int root = 2000;
	int node;
	for(int i = l; i <= r; i++) {
		if(pre[in[i]] < root) {
			root = pre[in[i]];
			node = i;
		}
	}
	return node;
}
int makeTree(int l, int r) {
	if(l == r) return in[l]; 
	if(l > r) return 0;
	int root = getRoot(l, r);
	tree[in[root]].X = makeTree(l, root - 1);
	tree[in[root]].Y = makeTree(root + 1, r);
	return in[root];
}
void postorder(int node) {
	if(tree[node].X) postorder(tree[node].X);
	if(tree[node].Y) postorder(tree[node].Y);
	cout << node << " ";
}
int main() {
	int tc; cin >> tc;
	while(tc--) {
		cin >> n;
		for(int i =  0; i <= n; i++) {
			tree[i].X = 0;
			tree[i].Y = 0;
		}
		for(int i = 1; i <= n; i++) {
			int x; cin >> x;
			pre[x] = i;
		}
		for(int i = 1; i <= n; i++) {
			cin >> in[i];
		}
		makeTree(1, n);
		int root = getRoot(1, n);
		postorder(in[root]);
		cout << "\n";
	}
}
