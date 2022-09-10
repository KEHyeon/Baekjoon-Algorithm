#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int size, x, root;
pair<int,int> tree[1000000];
int* find(int num, int parent) {
	if(num > parent) {
		if(tree[parent].Y == 0) return &tree[parent].Y;
		return find(num, tree[parent].Y);
	}
	else if(num < parent) {
		if(tree[parent].X == 0) return &tree[parent].X;
		return find(num, tree[parent].X);
	}
}
void postOrder(int cur) {
	if(tree[cur].X) postOrder(tree[cur].X);
	if(tree[cur].Y) postOrder(tree[cur].Y);
	cout << cur <<  "\n";
}
int main() {
	cin >> root;
	while(cin >> x) {
		int* address = find(x, root);
		*address = x;
	}
	postOrder(root);
}
