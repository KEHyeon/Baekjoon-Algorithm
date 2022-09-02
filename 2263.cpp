#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n;
int in[100001];
int post[100001];
pair<int,int> tree[100001];
int getRoot(int l, int r) {
	int root = -1;
	int rooti;
	for(int i = r; i >= l; i--) {
		if(post[in[i]] > root) {
			root = post[in[i]];
			rooti = i;
		}
	}
	return rooti;
}
int makeTree(int l, int r) {
	if(l > r) return 0;
	if(l == r) return in[l];
	int root = getRoot(l, r);
	tree[in[root]].X = makeTree(l, root - 1);
	tree[in[root]].Y = makeTree(root + 1, r);
	return in[root];
}
void preOrder(int root) {
	cout << root << " ";
	if(tree[root].X) preOrder(tree[root].X);
	if(tree[root].Y) preOrder(tree[root].Y);
}
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> in[i];
	}
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		post[x] = i;
	}
	makeTree(0, n - 1);
	int root = getRoot(0, n - 1);
	preOrder(in[root]);	
}
